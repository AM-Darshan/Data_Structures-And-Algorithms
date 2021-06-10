#include<bits/stdc++.h>
using namespace std;

int max1(int a,int b){
    return a>b?a:b;
}
int minJumps2(int arr[], int n)
{
    int step=arr[0];
    int maxreach=arr[0];
    int jump=1;
    if(n==1) return 0;
    if(arr[0] == 0) return -1;
    for(int i=1;i<n;i++){
        if(i==n-1)
            return jump;
        maxreach= max1(maxreach,arr[i]+i);
        step--;
        if(step==0){
            jump++;
            if(i>=maxreach){
                return -1;
            }
            step= maxreach-i;
        }
    }
    return 0;
}
int minJumps1(int arr[], int n)
{
    int dp[n];
    for(int i=0;i<n;i++) dp[i]=INT_MAX;
    dp[0]=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(dp[j]!= INT_MAX && (arr[j]+j>=i)){
                if(dp[j]+1<dp[i]){
                    dp[i]=dp[j]+1;
                }
            }
        }
    }
    if(dp[n-1]!=INT_MAX){
        return dp[n-1];
    }else{
        return -1;
    }
    return 0;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans= minJumps1(a,n);
    cout<<"0(N^2): "<<ans;
    ans= minJumps2(a,n);
    cout<<"\n0(N): "<<ans;
    return 0;
}