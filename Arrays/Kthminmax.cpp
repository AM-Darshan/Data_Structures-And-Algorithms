#include <bits/stdc++.h>
using namespace std;
#define LP(i, a, b) for (int i = a; i < b; i++)
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n;
    int a[n];
    LP(i,0,n){
        cin>>a[i];
    }
    cin>>k;
    // sort(a,a+n);
    // cout<<a[k-1]<<" "<<a[n-k];
    priority_queue<int,vector<int>,greater<int>> pq;
    LP(i,0,n){
        pq.push(a[i]);
    }
    int i=1,ans=0;
    while(!pq.empty()){
        if(i==k){
            ans= pq.top();
            break;
        }
        i++;
        pq.pop();
    }
    cout<<ans;
    return 0;
}