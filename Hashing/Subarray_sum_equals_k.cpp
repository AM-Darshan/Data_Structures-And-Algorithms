#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int n= nums.size();
    int sum=0;
    int count=0;
    unordered_map<int,int> mp;
    mp[0]++;
    for(int i=0;i<n;i++){
        sum+= nums[i];
        if(mp.find(sum-k) != mp.end()){
            count+= mp[sum-k];
        }
        mp[sum]++;
    }
    return count;
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
    int k;
    cin>>k;
    cout<<subarraySum(a,k);
    return 0;
}