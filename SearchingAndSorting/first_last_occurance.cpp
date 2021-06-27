#include<bits/stdc++.h>
using namespace std;

// Given a sorted array arr containing n elements with possibly duplicate elements, 
//the task is to find indexes of first and last occurrences of an element x in the given array.

int solve1(int a[],int n,int x,int tog){
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid= (low+high)/2;
        if(a[mid]<x)
            low= mid+1;
        else if(a[mid] >x)
            high= mid-1;
        else{
            ans= mid;
            if(tog == -1)
                high= tog+mid;
            else 
                low= mid+tog;
        }
    }
    return ans;
}
vector<int> find(int arr[], int n , int x)
{
   vector<int> index;
//    int id1= lower_bound(arr,arr+n,x) - arr; //gives index
//    int id2= upper_bound(arr,arr+n,x)- arr -1;
    int id1= solve1(arr,n,x,-1);
    int id2= solve1(arr,n,x,1);
   if(id1 == n)
        index.push_back(-1);
    else{
        index.push_back(id1);
        index.push_back(id2);
    }
    return index;
}
int main()
{
    int n,x;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>x;
    vector<int> ans= find(a,n,x);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}