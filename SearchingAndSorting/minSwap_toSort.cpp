#include<bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> &nums)
{
   int n= nums.size();
   vector< pair<int,int> > res(n);
    for(int i=0;i<n;i++){
        res[i]= {nums[i],i};
    }
    sort(res.begin(),res.end());
    int count=0;
    for(int i=0;i<n;i++){
        if(i == res[i].second){
            continue;
        }else{
            count++;
            swap(res[i],res[res[i].second]);
            i--;
        }
    }
    return count;
}
int main()
{
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    cout<<minSwaps(a);
    return 0;
}