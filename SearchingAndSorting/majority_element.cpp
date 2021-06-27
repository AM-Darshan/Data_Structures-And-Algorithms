#include<bits/stdc++.h>
using namespace std;

int majorityElement(int a[], int size)
{
    int ma= a[0];
    int count=1;
    for(int i=0;i<size;i++){
        if(a[i] == ma)
            count++;
        else
            count--;
        if(count==0){
            ma= a[i];
            count=1;
        }
    }
    int c=0;
    for(int i=0;i<size;i++){
        if(a[i]==ma)
            c++;
    }
    if(c>size/2)
        return ma;
    else 
        return -1;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<majorityElement(a,n);
    return 0;
}