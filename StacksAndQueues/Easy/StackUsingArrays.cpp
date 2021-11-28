#include <bits/stdc++.h>
using namespace std;

class Stack{
    int arr[10];
    int top=-1;
public: 
    void push(int val){
        arr[++top] =val;
    }
    int pop(){
        int ele = arr[top];
        top--;
        return ele;
    }
    int Top(){
        return arr[top];
    }
    int size(){
        return top+1;
    }
    bool Empty(){
        return top == -1;
    }
};
int main(){
    Stack s;
    s.push(6);
    s.push(10);
    cout<<s.size();
    cout<<s.Top();
    cout<<s.pop();
    
    cout<<s.pop();
    cout<<s.Empty();
    return 0;
}