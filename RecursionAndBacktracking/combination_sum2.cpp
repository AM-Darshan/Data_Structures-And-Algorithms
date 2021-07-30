#include<bits/stdc++.h>
using namespace std;


void findCombination(int ind,int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
    if(target==0){
        ans.push_back(ds);
        return;
    }
    for(int i= ind;i<arr.size();i++){
        if(i>ind && arr[i]==arr[i-1])
            continue;
        if(arr[i]>target)
            break;
        ds.push_back(arr[i]);
        findCombination(i+1,target-arr[i],arr,ans,ds);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(),candidates.end());
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0,target,candidates,ans,ds);
    return ans;
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
    cin >> tar;
    vector<vector<int>> res = combinationSum2(a, tar);
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