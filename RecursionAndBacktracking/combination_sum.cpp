#include<bits/stdc++.h>
using namespace std;

/*Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/
 
void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &res, vector<int> &ds){
    if(ind == arr.size()){
        if(target == 0){
            res.push_back(ds);
        }
        return;
    }

    if(arr[ind] <= target){
        ds.push_back(arr[ind]);
        findCombination(ind,target-arr[ind],arr,res,ds);
        ds.pop_back();
    }
    findCombination(ind+1,target,arr,res,ds);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> res;
    vector<int> ds;
    findCombination(0,target,candidates,res,ds);
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
    int tar;
    cin>>tar;
    vector<vector<int>> ans= combinationSum(a,tar);
    cout << "{ ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "], ";
    }
    cout << "}";
    return 0;
}