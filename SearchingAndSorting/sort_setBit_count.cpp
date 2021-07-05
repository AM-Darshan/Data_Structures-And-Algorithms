#include<bits/stdc++.h>
using namespace std;

//method1:
static bool comp(int a,int b){
    return __builtin_popcount(a)>__builtin_popcount(b);
}
void sortBySetBitCount1(int arr[], int n)
{
    stable_sort(arr,arr+n,comp);
}
//method2:
int countBits(int a)
{
    int count = 0;
    while (a)
    {
        if (a & 1)
            count += 1;
        a = a >> 1;
    }
    return count;
}

// Function to sort according to bit count
// This function assumes that there are 32
// bits in an integer.
void sortBySetBitCount(int arr[], int n)
{
    vector<vector<int>> count(32);
    int setbitcount = 0;
    for (int i = 0; i < n; i++)
    {
        setbitcount = countBits(arr[i]);
        count[setbitcount].push_back(arr[i]);
    }

    int j = 0; // Used as an index in final sorted array

    // Traverse through all bit counts (Note that we
    // sort array in decreasing order)
    for (int i = 31; i >= 0; i--)
    {
        vector<int> v1 = count[i];
        for (int i = 0; i < v1.size(); i++)
            arr[j++] = v1[i];
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sortBySetBitCount1(a,n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    sortBySetBitCount(a, n);
    for (int i = 0; i < n; i++)
        cout<<a[i]<<" ";
    return 0;
}