#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,i;
    cin>>n;
    int arr[n];
    unordered_set<int> set;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    int i;
    unordered_set<int> set;
    int cursum = 0;
    for (i = 0; i < n; i++)
    {
        cursum += arr[i];
        if (set.find(cursum) != set.end() || cursum == 0)
        {
           cout<<"YES";
           return 0;
        }
        set.insert(cursum);
    }
    cout<<"NO";
    return 0;
}