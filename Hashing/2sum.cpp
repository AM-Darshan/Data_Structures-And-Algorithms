#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> res;
    unordered_map<int,int> mpp;
    for(int i=0;i<nums.size();i++){
        if(mpp.find(target- nums[i]) != mpp.end()){
            res.push_back(mpp[target-nums[i]]);
            res.push_back(i);
            return res;
        }
        mpp[nums[i]]=i;
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    int t;
    cin>>t;
    vector<int> ans = twoSum(a,t);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}