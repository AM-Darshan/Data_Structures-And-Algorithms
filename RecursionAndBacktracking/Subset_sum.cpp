#include<bits/stdc++.h>
using namespace std;

void func(int ind, int sum, vector<int> &arr,int N,vector<int> &sumSubset){
    if(ind == N){
        sumSubset.push_back(sum);
        return;
    }

    func(ind+1,sum+arr[ind],arr,N,sumSubset);

    func(ind+1,sum,arr,N,sumSubset);
}
vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> sumSubset;
    func(0,0,arr,N,sumSubset);
    sort(sumSubset.begin(),sumSubset.end());
    return sumSubset;
}

vector<int> AllPossibleSum(vector<int> num)
{
    int n = num.size();
    vector<int> ans;
    for (int nums = 0; nums < (1 << n); nums++)
    {
        int sum=0;
        for (int i = 0; i < n; i++)
        {
            if (nums & (1 << i))
            {
                sum += num[i];
            }
        }
        ans.push_back(sum);
    }
    sort(ans.begin(), ans.end());
    return ans;
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
    //vector<int> ans= subsetSums(a,n);
    vector<int> ans = AllPossibleSum(a);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}