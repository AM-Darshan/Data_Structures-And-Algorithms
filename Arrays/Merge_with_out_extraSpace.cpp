#include<bits/stdc++.h>
using namespace std;

void display(int[],int[],int,int);
int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}

void mergeGAP(int arr1[], int arr2[], int n, int m)
{
    int i, j, gap = n + m;
    for (gap = nextGap(gap);
         gap > 0; gap = nextGap(gap))
    {
        // comparing elements in the first array.
        for (i = 0; i + gap < n; i++)
            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);

        // comparing elements in both arrays.
        for (j = gap > n ? gap - n : 0;
             i < n && j < m;
             i++, j++)
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);

        if (j < m)
        {
            // comparing elements in the second array.
            for (j = 0; j + gap < m; j++)
                if (arr2[j] > arr2[j + gap])
                    swap(arr2[j], arr2[j + gap]);
        }
    }
}

void mergeInsertion(int X[],int Y[],int m,int n){
    for (int i = 0; i < m; i++)
    {
        // compare the current element of `X[]` with the first element of `Y[]`
        if (X[i] > Y[0])
        {
            swap(X[i], Y[0]);
            int first = Y[0];

            // move `Y[0]` to its correct position to maintain the sorted
            // order of `Y[]`. Note: `Y[1…n-1]` is already sorted
            int k;
            for (k = 1; k < n && Y[k] < first; k++)
            {
                Y[k - 1] = Y[k];
            }

            Y[k - 1] = first;
        }
    }
}
void mergeExtra(int a[],int b[],int n,int m){
    int ans[n+m];
    int index=0;
    for(int i=0;i<n;i++){
        ans[index++]= a[i];
    }
    for (int i = 0; i < m; i++)
    {
        ans[index++] = b[i];
    }
    sort(ans,ans+(n+m));
    index=0;
    for (int i = 0; i < n; i++)
    {
        a[i]=ans[index++];
    }
    for (int i = 0; i < m; i++)
    {
        b[i]= ans[index++];
    }
    display(a,b,n,m);
}
void display(int a[],int b[],int n,int m){
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout<<"\n";
    for (int i = 0; i < m; i++)
    {
        cout << b[i] << " ";
    }
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
    int m;
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    //mergeGAP(a,b,n,m);
    mergeInsertion(a,b,n,m);
    //mergeExtra(a,b,n,m);
    display(a,b,n,m);
    return 0;
}