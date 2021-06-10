#include<bits/stdc++.h>
using namespace std;

void union_inter(int a[],int n,int b[],int m){
    int i=0,j=0;
    while(i<n && j<m){
        if(a[i] < b[j]){
            cout<<a[i]<<" ";
            i++;
        }else if(b[j] < a[i]){
            cout<<b[j]<<" ";
            j++;
        }else{
            cout<<a[i]<<" ";
            i++;
            j++;
        }
    }
    while(i<n){
        cout<<a[i]<<" ";
        i++;
    }
    while(j<m){
        cout<<b[j]<<" ";
        j++;
    }
}


int main()
{
    int n,m;
    cin >>n>>m;
    int a[n],b[m];
    unordered_map<int,int> map;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        map[a[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        map[b[i]]++;
    }
    union_inter(a,n,b,m);
    cout<<"\n"<<map.size();
    return 0;
}