#include <bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/sort-a-stack/1

stack<int> st;
void insert_val(int x){
    if (st.empty() || st.top() <= x){
        st.push(x);
        return;
    }
    else{
        int v = st.top();
        st.pop();
        insert_val(x);
        st.push(v);
    }
}
void sortStack(){
    if (st.size() > 0)
    {
        int x = st.top();
        st.pop();
        sortStack();
        insert_val(x);
    }
}
int main()
{
    st.push(4);
    st.push(3);
    st.push(6);
    st.push(1);
    sortStack();
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}