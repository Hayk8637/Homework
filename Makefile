all: link
makeDir:
	@mkdir -p bin obj lib
	@echo "Create: bin , obj , lib"
obj/encoder.o,decoder.o,test.o:makeDir  
	@g++ -c src/encoder.cpp -I inc -o obj/encoder.o
	@echo "Create: encoder.o"
	@g++ -c src/decoder.cpp -I inc -o obj/decoder.o
	@echo "Create: decoder.o"
	@g++ -c src/test.cpp -I inc -o obj/test.o
	@echo "Create: test.o"
lib/encoder.so,decoder.so,test.a: obj/encoder.o,decoder.o,test.o 
	@gcc -shared -fPIC obj/encoder.o -o lib/libencoder.so
	@echo "Create: encoder.so"
	@gcc -shared -fPIC obj/decoder.o -o lib/libdecoder.so
	@echo "Create: decoder.so"
	@ar -cvq lib/libtest.a -o obj/test.o
	@echo "Create: test.a"
link: lib/encoder.so,decoder.so,test.a
	@g++ src/main.cpp -I inc -L ./lib -ltest -ldecoder -lencoder  -o bin/main.out
	bin/main.out
clear:
	@rm -rf bin obj lib
	@echo "Deleted"