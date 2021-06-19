#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int n = nums.size(), res = nums[0], l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        l = (l ? l : 1) * nums[i];
        r = (r ? r : 1) * nums[n - 1 - i];
        res = max(res, max(l, r));
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<maxProduct(arr);
    return 0;
}