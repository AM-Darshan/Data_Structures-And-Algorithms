#include<bits/stdc++.h>
using namespace std;

void movneg(int a[],int n){
    int low=0,high=n-1;
    while(low<=high){
        if(a[low]<0 && a[high]<0){
            low++;
        }else if(a[low]>0 && a[high]< 0){
            swap(a[low],a[high]);
            low++;
            high--;
        }else if(a[low]>0 && a[high]>0){
            high--;
        }else{
            high--;
            low++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
void shiftleft(int a[],int n){
    int i=-1;
    int pivot=0;
    for(int j=0;j<n;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    for (int j = 0; j< n; j++)
    {
        cout << a[j] << " ";
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    movneg(a,n);
    cout<<"\n";
    shiftleft(a,n);
    return 0;
}