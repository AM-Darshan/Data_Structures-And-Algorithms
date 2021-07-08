#include<bits/stdc++.h>
using namespace std;


int lengthOfLongestSubstringOptimal(string s)
{
    vector<int> mpp(256,-1);

    int left=0,right=0;
    int n= s.size();
    int len=0;
    while(right<n){
        if(mpp[s[right]]!=-1){
            left= max(left, mpp[s[right]]+1);
        }
        mpp[s[right]]= right;

        len= max(len,right-left+1);
        right++;
    }

    return len;
}
int lengthOfLongestSubstring(string s)
{
    int left=0, right=0;
    int n= s.length(), ans=0;
    unordered_set<char> freq;
    while(left<n && right<n){
        if(freq.find(s[right]) == freq.end()){
            freq.insert(s[right++]);
            ans= max(ans,right-left);
        }
        else{
            freq.erase(s[left++]);
        }
    }
    return ans;
}
int main()
{
    string str;
    cin>>str;
    cout<<lengthOfLongestSubstringOptimal(str);
    return 0;
}