#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int q;
    cin>>q;
    sort(a,a+n);
    int pre[n+1];
    pre[0]= 0;
    for(int i=1;i<=n;i++)
        pre[i]= pre[i-1]+a[i-1];
    
    while(q--){
        int x;
        cin>>x;

        int idx= upper_bound(a,a+n,x) -a;

        cout<<idx<<" "<<pre[idx]<<endl;
    }
    return 0;
}