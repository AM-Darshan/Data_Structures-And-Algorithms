#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int n = nums.size();

        // Sort the generated subset. This will help to identify duplicates.
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets;

        int maxNumberOfSubsets = pow(2, n);
        // To store the previously seen sets.
        unordered_set<string> seen;

        for (int subsetIndex = 0; subsetIndex < maxNumberOfSubsets; subsetIndex++)
        {
            // Append subset corresponding to that bitmask.
            vector<int> currentSubset;
            string hashcode = "";
            for (int j = 0; j < n; j++)
            {
                // Generate the bitmask
                int mask = 1 << j;
                int isSet = mask & subsetIndex;
                if (isSet != 0)
                {
                    currentSubset.push_back(nums[j]);
                    // Generate the hashcode by creating a comma separated string of numbers in the currentSubset.
                    hashcode.append(to_string(nums[j]) + ",");
                }
            }

            if (seen.find(hashcode) == seen.end())
            {
                subsets.push_back(currentSubset);
                seen.insert(hashcode);
            }
        }

        // for (auto it = seen.begin(); it != seen.end();++it)
        //     cout << ' ' << *it;
        // cout<<endl;
        return subsets;
    }
};

void findSubsets(int ind, vector<int> &nums, vector<int> &ds,vector<vector<int>> &res){
    res.push_back(ds);
    for(int i=ind;i<nums.size();i++){
        if(i!=ind && nums[i] == nums[i-1]) 
            continue;
        
        ds.push_back(nums[i]);
        findSubsets(i+1,nums,ds,res);
        ds.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> ds;
    sort(nums.begin(),nums.end());
    findSubsets(0,nums,ds,res);
    return res;
}
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
    //vector<vector<int>> ans = s.subsetsWithDup(a);
    vector<vector<int>> ans = subsetsWithDup(a);
    cout<<"{ ";
    for(int i=0;i<ans.size();i++){
        cout<<"[";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"], ";
    }
    cout<<"}";
    return 0;
}

