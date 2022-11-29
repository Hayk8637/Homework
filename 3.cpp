#include <iostream>
#include <stack>

using namespace std;


int main(){
    int a[9] = {1,2,3,4,5,6,7,8,9};
    stack <int> b ;
    for (int i = 0; i < 9; i++)
    {
        b.push(a[i]);
    }
    for (int i = 0; i < 9; i++)
    {
        a[i]=b.top();
        b.pop();
    }
    for (int i = 0; i < 9; i++)
    {
        cout<<a[i]<<",";
    }
    cout<<endl;
    
}