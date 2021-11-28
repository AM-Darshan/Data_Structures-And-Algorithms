#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1#
//https://leetcode.com/problems/next-greater-element-ii/

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<long long> st;
        vector<long long> nge(n);
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            
            if(st.empty())
                nge[i]= -1;
            else
                nge[i]= st.top();
            
            st.push(arr[i]);
        }
        return nge;
    }
    
    //Time O(N) for one pass
    //Spce O(N) in worst case

    vector<int> nextGreaterElements(vector<int>& nums) {
        int n= nums.size();
        stack<int> st;
        vector<int> nge(n);
        for(int i=2*n-1;i>=0;i--){
            
            while(!st.empty() && st.top()<=nums[i%n]){
                st.pop();
            }
            
            if(st.empty())
                nge[i%n]= -1;
            else
                nge[i%n]= st.top();
            
            st.push(nums[i%n]);
          
        }
        return nge;
    }

    /*
    vector<int> nextGreaterElements(vector<int>& A) {
        int n = A.size();
        vector<int> stack, res(n, -1);
        for (int i = 0; i < n * 2; ++i) {
            while (stack.size() && A[stack.back()] < A[i % n]) {
                res[stack.back()] = A[i % n];
                stack.pop_back();
            }
            stack.push_back(i % n);
        }
        return res;
    }
    */

};
int main()
{
    
    return 0;
}