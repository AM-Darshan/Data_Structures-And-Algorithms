#include<bits/stdc++.h>
using namespace std;

class Queue{
    int arr[5];
    int front=-1;
    int rear=-1;
    int cnt=0,n=5;
public:
    int push(int val){
        if(cnt == n) return -1;
        arr[rear%n] = val;
        rear++;
        cnt++;
    }

    int pop(){
       if(cnt == 0) return -1;
       int ele = arr[front%n];
       arr[front%n] = -1;
       front++;
       cnt--; 
       return ele;
    }
    int Top(){
        if(cnt == 0) return -1;
        return  arr[front%n];
    } 
};
int main()
{
    Queue q;
    q.push(2);
    q.push(5);
    q.push(1);
    cout<<q.pop()<<" ";
    cout<<q.Top()<<" ";
    cout<<q.pop()<<" ";
    cout<<q.pop()<<" ";
    cout<<q.Top()<<" ";
    cout<<q.pop()<<" ";
    return 0;
}