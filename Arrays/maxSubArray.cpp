#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int nums[], int n)
{
    int sum = 0, max = INT_MIN;
    for (int i = 0; i <n; i++)
    {
        sum += nums[i];
        if (sum > max)
        {
            max = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return max;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=maxSubarraySum(a,n);
    cout<<ans;
    return 0;
}