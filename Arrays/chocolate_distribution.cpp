#include<bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m)
{
    if(n==0 || m==0)
        return 0;

    sort(a.begin(),a.end());
    
    if(n<m)
        return -1;

    long long int mindiff= INT_MAX;

    for(int i=0;i + m - 1 < n;i++){
        long long int diff = a[i + m -1] - a[i];
        if(diff<mindiff)
            mindiff = diff;
    }
     
    return mindiff;
}
int main()
{
    long long n,i,m;
    cin>>m>>n;
    vector<long long> arr;
    for(i=0;i<n;i++) {
        long long x;
        cin>>x;
        arr.push_back(x);
    }   
    cout<<findMinDiff(arr,n,m);
    return 0;
}