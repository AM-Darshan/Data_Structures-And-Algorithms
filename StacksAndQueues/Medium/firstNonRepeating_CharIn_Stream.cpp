#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
string FirstNonRepeating(string A)
{
    queue<char> q;
    string ans ="";
    int freq[26]={0};

    for(int i=0;i<A.size();i++){
        q.push(A[i]);
        freq[A[i]-97]++;

        while(!q.empty() && freq[q.front()-97]!=1)
            q.pop();
        
        if(!q.empty()){
            ans.push_back(q.front());
        }

        else{
            ans.push_back('#');
        }
    }
    return ans;
}
int main()
{
    string s="aabc";
    cout<<FirstNonRepeating(s);
    return 0;
}