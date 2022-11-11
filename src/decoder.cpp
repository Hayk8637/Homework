#include <string>
#include <decoder.h>
std::string decode(std::string a , int n){
    int len = a.length();
    if(n>=26){
        n-=26;
    }
    for (int i = 0; i < len; i++) {
        if( int(a[i]) == 32){
            continue;
        } else if (int(a[i])<= 90 && int(a[i])>= 65){
            if(int(a[i])-n < 65) {
                a[i] = 26-n+int(a[i])  ; 
            }else {
                a[i] = int(a[i])-n;
            }
        }else if (int(a[i]) >= 97 && int(a[i])<=122){
            if(int(a[i])-n < 97 ) {
                a[i] =26 - n + int(a[i])  ; 
            }else {
                a[i] = int(a[i])-n;
            }
        }
        continue;
    }
    return a;
}
