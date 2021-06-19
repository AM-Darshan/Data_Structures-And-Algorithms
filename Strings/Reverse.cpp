#include<bits/stdc++.h>
using namespace std;

void reverseString(vector<char>& s) 
{
    int i,n= s.size();
    int low=0,high=n-1;
    while(low<high){
        swap(s[low],s[high]);
        low++;
        high--;
    }
}
int main()
{
    int n,i;
    cin>>n;
    vector<char> str;
    for(i=0;i<n;i++){
        char x;
        cin>>x;
        str.push_back(x);
    }
    reverseString(str);
    for (i = 0; i < n; i++)
    {
        cout<<str[i]<<" ";
    }
    return 0;
}