#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/sliding-window-maximum/

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> maxEle;
    deque<int> dq;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1)
        {
            maxEle.push_back(nums[dq.front()]);
        }
    }
    return maxEle;
}
int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7 };
    int k = 3; 
    nums = maxSlidingWindow(nums,k);
    for(int x:nums){
        cout<<x<<" ";
    }
    return 0;
}