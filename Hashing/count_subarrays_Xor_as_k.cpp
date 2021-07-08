#include<bits/stdc++.h>
using namespace std;

int subarrayXor(vector<int> &arr,int k)
{
    map<int, int> freq;
    int xr= 0;
    int count=0;
    for(auto it: arr){
        xr = xr ^ it;
        
        if(xr==k)
            count++;
        
        if(freq.find(xr^k) != freq.end()){
            count+= freq[xr^k];
        }
        
        freq[xr]+=1;
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    int k;
    cin >> k;
    cout<<subarrayXor(a,k);
    return 0;
}