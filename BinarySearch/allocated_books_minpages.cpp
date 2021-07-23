#include<bits/stdc++.h>
using namespace std;

bool isPossible(int A[],int n,int pages,int students){
    int cnt = 0;
    int sumAllocated = 0;
    for (int i = 0; i < n; i++)
    {
        if (sumAllocated + A[i] > pages)
        {
            cnt++;
            sumAllocated = A[i];
            if (sumAllocated > pages)
                return false;
        }
        else
        {
            sumAllocated += A[i];
        }
    }
    if (cnt < students)
        return true;
    return false;
}
int findPages(int arr[], int n, int m)
{
    if(m>n)
        return -1;
    int low = arr[0], high=0;
    for(int i=0;i<n;i++){
        high+= arr[i];
        low= min(low,arr[i]);
    }
    while(low<=high){
        int mid= (low+high) >> 1;
        
        if(isPossible(arr,n,mid,m)){
            high= mid-1;
        }
        else{
            low= mid+1;
        }
    }
    return low;
}
int main()
{
    int n,m;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin>>m;
    cout<<findPages(a,n,m);
    return 0;
}