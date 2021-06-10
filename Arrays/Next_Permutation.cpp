#include<bits/stdc++.h>
using namespace std;

void dis(vector<int> &nu){
    cout<<"\n[";
    for (int i = 0; i < nu.size(); i++)
    {
        cout << nu[i] << ",";
    }
    cout<<"]\n";
}
void nextPermutation(vector<int> &nums)
{
    int n=nums.size(),index1,index2;
    for(index1=n-2;index1>=0;index1--){
        if(nums[index1]<nums[index1+1]){
            break;
        }
    }
    if(index1<0){
        reverse(nums.begin(),nums.end()); // last purmutation is given, hence reverse 
    }else{
        for(index2=n-1;index2>index1;index2--){
            if(nums[index2]>nums[index1]){
                break;
            }
        }
        swap(nums[index1], nums[index2]);
        reverse(nums.begin() + index1 + 1, nums.end());
    }
    
}
int main()
{
    int n,i;
    cin>>n;
    vector<int> vi;
    for (i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vi.push_back(x);
    }
    nextPermutation(vi);
    dis(vi);
    return 0;
}