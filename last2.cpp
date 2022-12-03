#include <iostream>

#include <vector>
#include <set>
using namespace std;
int third_max(vector <int> &vec){
    set <int> s;
    for (int i = 0; i<vec.size(); i++)
    {
        s.insert(vec[i]);
    }
    set <int> :: iterator it = s.begin();
    if(s.size()==1){
        return *it;
    }
    it++;
    if (s.size()==2)
    {
        return *it;
    }
    it--;
    for (auto i =3 ; i < s.size(); i++)
    {
        it++;
    }
    return *it;   
    
}


int main(){

    
vector <int> vec = {3,7,20,39};
    cout<<third_max(vec)<<endl;
    return 0;
}