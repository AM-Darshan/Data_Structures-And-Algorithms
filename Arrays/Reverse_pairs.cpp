#include<bits/stdc++.h>
using namespace std;

// Given an integer array nums, return the number of reverse pairs in the array.
// A reverse pair is a pair(i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].
//1 <= nums.length <= 5 * 10^4
// - 2^31 <= nums[i] <= 2^31 - 1 

int merge(vector<int> &nums,int low,int mid, int high){
    vector<int> temp;
    int count=0;
    int j=mid+1;
    for(int i=low;i<=mid;i++){
        while(j<=high && nums[i] > 2LL * nums[j]){
            j++;
        }
        count+= (j- (mid+1));
    }

    int left=low, right=mid+1;
    while(left<=mid && right<=high){
        if(nums[left] <= nums[right]){
            temp.push_back(nums[left++]);
        }
        else{
            temp.push_back(nums[right++]);
        }
    }
    while(left<=mid){
        temp.push_back(nums[left++]);
    } 
    while(right<=high){
        temp.push_back(nums[right++]);
    }

    for(int i=low;i<=high;i++){
        nums[i]= temp[i-low];
    }
    return count;
}
int mergeSort(vector<int> &nums,int low,int high){
    int mid;
    if(low>=high) return 0;

    mid=(low+high)/2;
    int inv= mergeSort(nums,low,mid);
    inv+= mergeSort(nums,mid+1,high);
    inv+= merge(nums,low,mid,high);
    return inv;
}
int reversePairs(vector<int> &nums)
{
    return mergeSort(nums,0,nums.size()-1);
}
int reversePairs1(vector<int> &nums)
{
    int n= nums.size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i] > 2*nums[j]){
                count++;
            }
        }
    }
    return count;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<reversePairs(arr);
    return 0;
}