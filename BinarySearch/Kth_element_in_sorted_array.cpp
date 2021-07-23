#include<bits/stdc++.h>
using namespace std;

int kthElement1(int arr1[], int arr2[], int n, int m, int k)
{
    int x = 0, i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            x++;
            if (x == k)
                return arr1[i];
            i++;
        }
        else
        {
            x++;
            if (x == k)
                return arr2[j];
            j++;
        }
    }
    while (i < n)
    {
        x++;
        if (x == k)
            return arr1[i];
        i++;
    }
    while (j < m)
    {
        x++;
        if (x == k)
            return arr2[j];
        j++;
    }
    return 0;
}

int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    if(n>m){
        return kthElement(arr2,arr1,m,n,k);
    }

    int low= max(0,k-m), high= min(k,n);

    while(low<=high){
        int cut1= (low+high)>>1;
        int cut2= k -cut1;
        int l1= cut1==0? INT_MIN : arr1[cut1-1];
        int l2= cut2==0? INT_MIN : arr2[cut2-1];
        int r1= cut1==n? INT_MAX : arr1[cut1];
        int r2= cut2==m? INT_MAX : arr2[cut2];

        if(l1<=r2 && l2<=r1){
            return max(l1,l2);
        }
        else if(l1 > r2){
            high = cut1-1;
        }
        else{
            low= cut1 + 1;
        }
    }
    return 1;
}
int main()
{
    int n,m;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    int k;
    cin>>k;
    cout<<kthElement(a,b,n,m,k);
    return 0;
}