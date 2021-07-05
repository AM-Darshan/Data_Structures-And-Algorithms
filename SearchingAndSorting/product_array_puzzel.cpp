#include<bits/stdc++.h>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int>& nums, int n)
{
    vector<long long int> left(n),right(n);
    left[0]= 1;
    right[n-1]=1;
    for(int i=1;i<n;i++){
        left[i]= left[i-1]*nums[i-1];
    }
    for (int i = n-2; i>=0; i--)
    {
        right[i] = right[i + 1] * nums[i + 1];
    }
    for (int i = 0; i < n; i++)
    {
        nums[i] = left[i] *right[i];
    }
    return nums;
}
void productArray(vector<long long int>& nums, int n)
{
    if (n == 1)
    {
        cout << 0;
        return;
    }
    vector<long long int> prod(n);
    for (int i = 0; i < n; i++)
    {
        prod[i]=1;
    }
    int temp=1;
    for(int i=0;i<n;i++){
        prod[i]=temp;
        temp*= nums[i];
    }
    temp=1;
    for(int i=n-1;i>=0;i--){
        prod[i]*= temp;
        temp*= nums[i];
    }
  
    for(int i=0;i<n;i++){
        cout<<prod[i]<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    vector<long long int> a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    productArray(a,n);
    cout<<endl;
    vector<long long int> ans= productExceptSelf(a,n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}