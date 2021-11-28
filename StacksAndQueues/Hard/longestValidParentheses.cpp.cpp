#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/valid-substring0624/1
//https://leetcode.com/problems/longest-valid-parentheses/

int findMaxLen2(string s) //1 stacks
{
    stack<int> idx;
    idx.push(-1);
    int len = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(')
            idx.push(i);
        
        else{
            idx.pop();
            
            if(idx.empty()){
                idx.push(i);
            }
            
            else{
                len = max(len, i - idx.top());
            }
        }
    }
    return len;
}
int findMaxLen1(string s) //2 stacks
{
    stack<char> ch;
    stack<int> idx;
    idx.push(-1);
    int len =0;
    for(int i=0;i<s.length();i++){
        if(s[i] == '('){
            ch.push(s[i]);
            idx.push(i);
        }

        else{
            if(!ch.empty()){
                ch.pop();
                idx.pop();
                len = max(len, i - idx.top());
            }
           else{
               idx.push(i);
           }
        }   
    }
    return len;
}

int longestValidParentheses(string s) //no stack
{
    
    int left=0,right=0;
    int maxi=0;
    for(int i=0;i<s.length();i++){
        if(s[i] == '(')
            left++;
        else    
            right++;
        
        if(left == right)
            maxi= max(maxi, left+right);
        if(right > left)
            left =right =0;
    }

    left = right =0;

    for (int i = s.length()-1; i>=0; i--)
    {
        if (s[i] == '(')
            left++;
        else
            right++;

        if (left == right)
            maxi = max(maxi, left + right);
        if (left > right)
            left = right = 0;
    }
    return maxi;
}
int main()
{
    string str = "()(())(";
    cout<<findMaxLen2(str)<<endl;
    cout<<longestValidParentheses(str);
    return 0;
}