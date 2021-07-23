#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays1(vector<int> &nums1, vector<int> &nums2)
{
    int n= nums1.size(),m = nums2.size();
    int n1=-1,n2=-1;
    double ans=0;
    int i=0,j=0,count;
    if((n+m)%2==1){
        for(count=0;count<=(n+m)/2;count++){
            if(i!=n && j!=m){
                n1= (nums1[i]<nums2[j])?nums1[i++]:nums2[j++];
            }
            else if(i<n){
                n1= nums1[i++];
            }
            else{
                n1= nums2[j++];
            }
        }
        ans= n1;
    }
    else{
        for (count = 0; count <= (n + m) / 2; count++)
        {
            n2= n1;
            if (i != n && j != m)
            {
                n1 = (nums1[i] < nums2[j]) ? nums1[i++] : nums2[j++];
            }
            else if (i < n)
            {
                n1 = nums1[i++];
            }
            else
            {
                n1 = nums2[j++];
            }
        }
        ans = (double)(n1+n2)/2.0;
    }
    return ans;
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    if(nums2.size() < nums1.size())
        return findMedianSortedArrays(nums2,nums1);
    
    int n1= nums1.size();
    int n2= nums2.size();
    int low=0,high=n1;

    while(low<=high){
        int cut1= (low+high)>>1;
        int cut2= (n1+n2+1)/2 - cut1;

        int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
        int left2= cut2 == 0 ? INT_MIN : nums2[cut2-1];

        int right1= cut1 == n1 ? INT_MAX : nums1[cut1];
        int right2= cut2 == n2 ? INT_MAX : nums2[cut2];

        if(left1<=right2 && left2<=right1){
            if((n1+n2)% 2 == 0){
                return (max(left1,left2) + min(right1,right2)) /2.0;
            }else{
                return max(left1,left2);
            }
        }
        else if(left1>right2){
            high= cut1-1;
        }
        else{
            low= cut1+1;
        }
    } 
    return 0.0;
}
int main()
{
    int n,m;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    cin >> m;
    vector<int> b;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }
    cout<<findMedianSortedArrays(a,b);
    return 0;
}