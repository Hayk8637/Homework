#include <iostream>
#include <encoder.h>
#include <decoder.h>
#include <test.h>
using namespace std;
int main(){
    string str ;
    int n;
    while(true){
        cin>>str;
        if(str=="break"){
            break;
        }
        cin>>n;
        cout<<unit_test(str,n)<<endl;
    }
    ;

    return 0;
}