#include<bits/stdc++.h>
using namespace std;

vector<int> valueEqualToIndex(int arr[], int n)
{
    vector<int> vali;
    for(int i=0;i<n;i++){
        if(arr[i] == i+1)
            vali.push_back(i+1);
    }
    return vali;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<int> ans= valueEqualToIndex(a,n);
    for (int i = 0; i < ans.size(); i++)
        cout<< ans[i]<<" ";
    return 0;
}