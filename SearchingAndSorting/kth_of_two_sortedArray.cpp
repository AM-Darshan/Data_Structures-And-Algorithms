#include<bits/stdc++.h>
using namespace std;

int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    int x=0,i=0,j=0;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            x++;
            if(x == k)
                return arr1[i];
            i++;
        }
        else{
            x++;
            if(x==k)
                return arr2[j];
            j++;
        }
    }
    while(i<n){
        x++;
        if (x == k)
            return arr1[i];
        i++;
    }
    while(j<m){
        x++;
        if (x == k)
            return arr2[j];
        j++;
    }
    return 0;
}
int main()
{
    int n,m,k;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    cin>>k;
    cout<<kthElement(a,b,n,m,k);
    return 0;
}