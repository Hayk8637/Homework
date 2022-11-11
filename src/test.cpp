#include <string>
#include <encoder.h>
#include <decoder.h>
#include <test.h>

bool unit_test(std::string a , int n){
    std::string b = encode(a , n);
    if(a == decode(b,n)){
        return true;
    } else {
        return false;
    }
}