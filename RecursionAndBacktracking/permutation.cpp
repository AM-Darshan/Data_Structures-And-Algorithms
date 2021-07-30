#include<bits/stdc++.h>
using namespace std;


class SolutionRecurOptimal{
    public:
        void recurPermute(int index,vector<int> &nums,vector<vector<int>> &ans){
            if(index == nums.size()){
                ans.push_back(nums);
                return;
            }
            for(int i=index;i<nums.size();i++){
                swap(nums[i],nums[index]);
                recurPermute(index+1,nums,ans);
                swap(nums[index],nums[i]);
            }
        }
        vector<vector<int>> permute(vector<int> &nums)
        {
            vector<vector<int>> ans;
            recurPermute(0,nums, ans);
            return ans;
        }
};
class SolutionRecur{
    public:
    void recurPermute(vector<int> &ds,vector<int> &nums, vector<vector<int>> &ans,int freq[]){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i]=1;
                recurPermute(ds,nums,ans,freq);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++){
            freq[i]=0;
        }
        recurPermute(ds,nums,ans,freq);
        return ans;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    SolutionRecur s;
    SolutionRecurOptimal s1;
    vector<vector<int>> res= s1.permute(a);
    //vector<vector<int>> res = s.permute(a);
    cout << "{ ";
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << "], ";
    }
    cout << "}";
    return 0;
}