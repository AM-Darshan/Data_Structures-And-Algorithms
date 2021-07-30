#include <bits/stdc++.h>
using namespace std;


class Solution2{
    public:
        void func(vector<int> &nums,vector<vector<int>> &ans,vector<int> &ds,int freq[]){
            if(ds.size()== nums.size()){
                ans.push_back(ds);
                return;
            }
            for(int i=0;i<nums.size();i++){
                if(freq[i])
                    continue;
                if(i>0 && nums[i-1] == nums[i] && !freq[i-1])
                    continue;
                freq[i]= 1;
                ds.push_back(nums[i]);
                func(nums,ans,ds,freq);
                freq[i]=0;
                ds.pop_back();
            }
        } 
        vector<vector<int>> permuteUnique(vector<int> &nums)
        {
            sort(nums.begin(),nums.end());
            vector<vector<int>> ans;
            vector<int> ds;
            int freq[nums.size()];
            for (int i = 0; i < nums.size(); i++)
            {
                freq[i] = 0;
            }
            func(nums,ans,ds,freq);
            return ans;
        }
};
class Solution
{
public:
    void recursion(vector<int> num, int i, int j, vector<vector<int>> &res)
    {
        if (i == j - 1)
        {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++)
        {
            if (i != k && num[i] == num[k])
                continue;
            swap(num[i], num[k]);
            recursion(num, i + 1, j, res);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &num)
    {
        sort(num.begin(), num.end());
        vector<vector<int>> res;
        recursion(num, 0, num.size(), res);
        return res;
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
    Solution s;
    Solution2 s2;
    vector<vector<int>> res = s.permuteUnique(a);
    //vector<vector<int>> res = s2.permuteUnique(a);
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