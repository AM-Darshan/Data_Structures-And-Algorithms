#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/queue-reversal/1
void reverseQueue(queue<int> &q)
{
    if(q.empty()){
        return;
    }
    int x= q.front();
    q.pop();
    reverseQueue(q);
    q.push(x);
}

int main()
{
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(8);
    reverseQueue(q);
    while (!q.empty())
    {
        cout<< q.front()<<" ";
        q.pop();
    }
    return 0;
}