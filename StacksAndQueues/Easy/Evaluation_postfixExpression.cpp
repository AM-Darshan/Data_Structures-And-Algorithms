#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

int evaluatePostfix(string S)
{
    stack<int> st;
    for(int i=0;i<S.length();i++){
        char ch= S[i];
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            int x = st.top();
            st.pop();
            int y= st.top();
            st.pop();
            switch (S[i])
            {
                case '+': st.push(x+y);
                            break;
                case '-': st.push(y-x);
                            break;
                case '*': st.push(x*y);
                            break;
                case '/':   st.push(y/x);
                            break;
                default:
                    break;
            }
        }
        else{
            st.push(S[i]-48);
        }
    }
    return st.top();
}

int main()
{
    string s = "231*+9-";
    cout<<evaluatePostfix(s);
    return 0;
}