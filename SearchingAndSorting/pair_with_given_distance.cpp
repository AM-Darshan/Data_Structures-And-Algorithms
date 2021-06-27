#include<bits/stdc++.h>
using namespace std;


bool findPair(int arr[], int size, int n)
{
    sort(arr,arr+size);
    bool ans= false;
    for(int i=0;i<size;i++){
        int idx= upper_bound(arr+i+1,arr+size,n+arr[i])-arr-1;
        if(arr[idx]-arr[i]==n){
            ans= true;
            break;
        }
    }
    return ans;
}
bool findPair1(int arr[], int size, int n)
{
    unordered_map<int,int> map;
    bool ans= false;
    for(int i=0;i<size;i++){
        map[arr[i]]++;
    }
    for(int i=0;i<size;i++){
        int y= arr[i]+n;
        if(map[y]){
            ans= true;
            break;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int dif;
    cin>>dif;
    cout<<findPair(a,n,dif);
    return 0;
}