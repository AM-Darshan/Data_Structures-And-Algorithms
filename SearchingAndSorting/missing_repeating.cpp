
#include<bits/stdc++.h>
using namespace std;

int *findTwoElement(int *arr, int n)
{
    int a,b;
    for(int i=0;i<n;i++){
        if(arr[abs(arr[i])-1]<0){
            a= abs(arr[i]);
        }else{
            arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
        }
    }   
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            b= i+1;
            break;
        }
    }
    int *v= new int[2];
    v[0]=a;
    v[1]=b;

    return v;
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
    auto x= findTwoElement(a,n);
    cout<<x[0]<<" "<<x[1];
    return 0;
}