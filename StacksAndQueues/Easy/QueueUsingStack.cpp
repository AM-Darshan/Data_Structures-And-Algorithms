#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/implement-queue-using-stacks/
//https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1#

class Queue{
    stack<int> s1,s2;
public:
    void enQueue(int x){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int deQueue(){
        if(s1.empty()){
            cout<<"Empty";
            exit(0);
        }
        int ele = s1.top();
        s1.pop();
        return ele;
    }
};

class MyQueue {
public:
    stack<int> input,output; 
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int ele =peek();
        output.pop();
        return ele;
    }
    
    int peek() {
        if (output.empty())
            while (input.size())
                output.push(input.top()), input.pop();
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
 
    cout << q.deQueue() <<"\n";
    cout << q.deQueue() <<"\n";
    cout << q.deQueue() <<"\n";
    
    MyQueue que;
    que.push(1);
    que.push(2);
    que.push(3);
    cout<<que.pop()<<" ";
    cout<<que.pop()<<" ";
    cout<<que.pop()<<" ";
    return 0;
}