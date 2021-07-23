#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    int low=0;
    int high= nums.size()-2;
    while(low<=high){
        int mid= (low+high)>>1;
        if(nums[mid] == nums[mid^1]){
            low= mid+1;
        }else{
            high= mid -1;
        }
    }
    return nums[low];
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
    cout<<singleNonDuplicate(a);
    return 0;
}