#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isValidStack(string s)
{
    stack <char> str ; 
    char p;


    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == '[' || s[i] == '{' || s[i] == '(')
        {
            str.push(s[i]);
            continue;
        }
        if(str.empty())
        {
            return false;
        }
        if(s[i]== ')')
        {
            p = str.top();
            str.pop();
            if(p=='[' || p=='{')
            {
                return false;
            }
        }else if(s[i]==']')
        {
            p=str.top();
            str.pop();
            if(p=='{' || p=='(')
            {
                return false;
            }
        }else if(s[i]='}')
        {
            p=str.top();
            str.pop();
            if(p=='(' || p== '[')
            {
                return false;
            }
        }
        
    }
    return str.empty();
}


bool isValidVector(string s)
{
    vector <char> str ; 
    char p;


    for (int i = 0; i < s.length(); i++)
    {   
        if(s[i] == '[' || s[i] == '{' || s[i] == '(')
        {
            str.push_back(s[i]);
            continue;
        }
        if(str.empty())
        {
            return false;
        }
        if(s[i]== ')')
        {
            p = str.back();
            str.pop_back();
            if(p=='[' || p=='{')
            {
                return false;
            }
        }else if(s[i]==']')
        {
            p=str.back();
            str.pop_back();
            if(p=='{' || p=='(')
            {
                return false;
            }
        }else if(s[i]='}')
        {
            p=str.back();
            str.pop_back();
            if(p=='(' || p== '[')
            {
                return false;
            }
        }
        
    }
    return str.empty();
}



int main() {

    string str = "{}[]()";
    
    if(isValidVector(str)){
        cout<<"yes"<<endl;
    }else 
        cout<<"no"<<endl;
    return 0;
}


// [ ] ( ) { }