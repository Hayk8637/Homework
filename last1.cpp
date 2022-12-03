#include <iostream>
#include <vector>
#include <map>
using namespace std;

map <int , int> target (vector <int>& a , int t){
    map <int , int > n;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j< a.size(); j++)
        {
            if(i==j){
                continue;
            }    
            if (a[i]+a[j]==t)
            {
                n.insert (pair{i,j});
                return n;
            }
            
        }    
    }
    return n;   
}

int main(){
    vector <int> a = {3,3};
    int t = 6;
    map <int, int> p;
    p = target(a,t);
    return 0;
}