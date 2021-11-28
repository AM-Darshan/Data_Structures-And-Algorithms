#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

queue<int> modifyQueue(queue<int> q, int k)
{
    int n= q.size();
    stack<int> st;
    for(int i=0;i<k;i++){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    for(int i=0;i<n-k;i++){
        int x = q.front();
        q.pop();
        q.push(x);
    }

    return q;
}
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    int k=3;

    q = modifyQueue(q,k);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}