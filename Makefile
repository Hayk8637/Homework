
	cc := gcc
	mD := makeDir
	o/e.o := obj/encoder.o
	o/d.o := obj/decoder.o
	o/t.o := obj/test.o
	l/e.so := lib/encoder.so
	l/d.so := lib/decoder.so
	l/t.a := lib/test.a
	src := $(wildcard src/ *.c)
	obj := $(patsubst src/ *.c , %.0 , $(src))
	all: link
	$(mD):
		@mkdir -p bin obj lib
		@echo "Create: bin , obj , lib"
	$(o/e.o): $(mD)  
		@$(cc) -c src/encoder.cpp -I inc -o $@
		@echo "Create: encoder.o"
	$(o/d.o): $(mD)
		@$(cc) -c src/decoder.cpp -I inc -o $@
		@echo "Create: decoder.o"
	$(o/t.o): $(mD)
		@$(cc) -c src/test.cpp -I inc -o $@
		@echo "Create: test.o"
	$(l/e.so): $(o/e.o) 
		@$(cc) -shared -fPIC $< -o $@	
		@echo "Create: encoder.so"
	$(l/d.so): $(o/d.o)
		@$(cc) -shared -fPIC $< -o $@
		@echo "Create: decoder.so"
	$(l/t.a): $(o/t.o)	
		@ar -cvq $@ -o $<
		@echo "Create: test.a"
	link: $(l/e.so) $(l/d.so) $(l/t.a)
		@$(cc) src/main.cpp -I inc -L ./lib -ltest -ldecoder -lencoder  -o bin/main.out
		@echo "Link is create"
		
		@bin/main.out
		@echo "main.out is create"
	clear:
		@rm -rf bin obj lib
		@echo "Deleted"









		