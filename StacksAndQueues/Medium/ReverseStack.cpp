#include<bits/stdc++.h>
using namespace std;

//geeksforgeeks.org/reverse-a-stack-using-recursion/

stack<int> st;
void insert_bottom(int x){
    if(st.size() == 0)
        st.push(x);
    else{
        int a = st.top();
        st.pop();
        insert_bottom(x);
        st.push(a);
    }
}
void reverseStack(){
    if(st.size() > 0){
        int x = st.top();
        st.pop();
        reverseStack();
        insert_bottom(x);
    }
}
int main()
{
    
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    reverseStack();
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}