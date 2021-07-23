#include<bits/stdc++.h>
using namespace std;

int search2(vector<int> &A, int target)
{
    int n = A.size();
    int lo = 0, hi = n - 1;
    // find the index of the smallest value using binary search.
    // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
    // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (A[mid] > A[hi])
            lo = mid + 1;
        else
            hi = mid;
    }
    // lo==hi is the index of the smallest value and also the number of places rotated.
    int rot = lo;
    lo = 0;
    hi = n - 1;
    // The usual binary search and accounting for rotation.
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        int realmid = (mid + rot) % n;
        if (A[realmid] == target)
            return realmid;
        if (A[realmid] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}

int search(vector<int> &nums, int target)
{
    int n= nums.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid = (low+high)>>1;
        if(nums[mid] == target){
            return mid;
        }
        if(nums[low]<=nums[mid]){
            if(target >= nums[low] && target <= nums[mid]){
                high= mid-1;
            }else{
                low= mid+1;
            }
        }
        else{
            if(target >= nums[mid] && target <= nums[high]){
                low= mid+1;
            }else{
                high= mid-1;
            }
        }
    }
    return -1;
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
    int t;
    cin>>t;
    cout<<search(a,t);
    return 0;
}