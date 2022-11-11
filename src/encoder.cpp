#include <string>
#include <encoder.h>
using namespace std;
string encode(string a , int n){
    int len = a.length();
    if(n>=26){
        n-=26;
    }
    for (int i = 0; i < len; i++) {
        if( int(a[i])== 32){
            continue;
        } else if (int(a[i])<= 90 && int(a[i])>= 65){
            if(int(a[i])+n > 90) {
                a[i] = n + 26- int(a[i]) ; 
            }else {
                a[i] = int(a[i])+n;
            }
        }else if (int(a[i])>=97 && int(a[i])<=122){
            if(int(a[i])+n > 122) {
                a[i] = n + int(a[i]) -26; 
            }else {
                a[i] = int(a[i])+n;
            }
        }
        continue;
    }
    return a;
}
