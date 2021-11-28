#include<bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/next-smaller-element/

void printNSE(int arr[],int n){
    
    stack<int> st;
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
        
    }

    for(int x: ans){
        cout<<x<<" ";
    }
}
int main()
{
    int arr[] = {4, 8, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    printNSE(arr, n);
    return 0;
}