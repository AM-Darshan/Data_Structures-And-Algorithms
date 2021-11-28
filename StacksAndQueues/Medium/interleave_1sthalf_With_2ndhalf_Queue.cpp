#include<bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/interleave-first-half-queue-second-half/

void interLeaveQueue(queue<int> &q){
    if (q.size() % 2 != 0)
        cout << "Input even number of integers." << endl;
    
    stack<int> st;
    int n = q.size();
    for(int i=0;i<n/2;i++){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    for(int i=0;i<n/2;i++){
        q.push(q.front());
        q.pop();
    }

    for(int i=0;i<n/2;i++){
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    interLeaveQueue(q);
    int length = q.size();
    for (int i = 0; i < length; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}