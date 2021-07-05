//maximum sum such that no 2 elements are adjacent
#include<bits/stdc++.h>
using namespace std;

int dp[10001];
int FindMaxSumdp(int arr[], int n)
{
   
   if(n<=-1){
       return 0;
   }
   if(dp[n]!=-1){
       return dp[n];
   }
   int op1= arr[n]+FindMaxSumdp(arr,n-2);
   int op2= FindMaxSumdp(arr,n-1);
   return dp[n]= max(op1,op2);
}
int FindMaxSum(int arr[], int n)
{
    int incl = arr[0];
    int excl = 0;
    int excl_new;
    int i;

    for (i = 1; i < n; i++)
    {
        /* current max excluding i */
        excl_new = (incl > excl) ? incl : excl;

        /* current max including i */
        incl = excl + arr[i];
        excl = excl_new;
    }

    /* return max of incl and excl */
    return ((incl > excl) ? incl : excl);
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dp[n];
    memset(dp, -1, sizeof(dp));
    cout<<FindMaxSum(a,n)<<endl;
    cout<<FindMaxSumdp(a,n);
    return 0;
}