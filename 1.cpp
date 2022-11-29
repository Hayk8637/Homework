#include  <iostream>
using namespace std;

  
class stack
{
    int top;
    int high;
    int n;
    public:
    int myStack[1000]; 
    stack() 
    {   
        n = 0;
        top = -1; 
    }
    int Top(){
        return high;
    }
    bool push(int x){
        if (top >= 999) {
            return false;
        }
        else {
            n++;
            myStack[++top] = x;
            high = x;
        return true;
        }
    }
    int size(){
        return n;
    }
    int pop(){
        if (top < 0) {
            return 0;
        } 
        else {
            int item = myStack[top--];
            high = myStack[top];
            return item;
        }
    }
    bool isEmpty(){
        return (top < 0);
    }
};

  


int main()
{
   stack stack;
   stack.push(2);
   stack.push(4);
   stack.push(6);
   cout<< stack.Top() <<endl;
   return 0;
}