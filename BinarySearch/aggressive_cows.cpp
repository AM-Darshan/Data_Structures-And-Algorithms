#include<bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int cows, int minDist){
    int cntcows =1;
    int lastPlacedCow= arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]- lastPlacedCow >= minDist){
            cntcows++;
            lastPlacedCow= arr[i];
        }
    }
    if(cntcows>=cows)
        return true;
    else
        return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,cows;
        cin>>n>>cows;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);

        int low=1,high= a[n-1]- a[0];
        while(low<=high){
            int mid= (low + high) >>1;
            if(isPossible(a,n,cows,mid)){
                low = mid+1;
            }
            else{
                high= mid-1;
            }
        }
        cout<<high<<"\n";
    }
    return 0;
}