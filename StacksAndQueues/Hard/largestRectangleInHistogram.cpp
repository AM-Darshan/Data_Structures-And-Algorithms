#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/largest-rectangle-in-histogram/
//https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1#


class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        int leftSmall[n], rightSmall[n];
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            if (st.empty())
                leftSmall[i] = 0;
            else
                leftSmall[i] = st.top() + 1;
            st.push(i);
        }

        // clear the stack to be re-used
        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            if (st.empty())
                rightSmall[i] = n - 1;
            else
                rightSmall[i] = st.top() - 1;

            st.push(i);
        }

        int maxA = 0;
        for (int i = 0; i < n; i++)
        {
            maxA = max(maxA, heights[i] * (rightSmall[i] - leftSmall[i] + 1));
        }
        return maxA;
    }

    int largestRectangleAreaOptimal(vector<int> &heights)
    {
        stack<int> st;
        int maxA = 0;
        int n = heights.size();
        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
            {
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                // cout << i << " " << width << " " << height << endl;
                maxA = max(maxA, width * height);
            }
            st.push(i);
        }
        return maxA;
    }
};

long long getMaxArea(long long arr[], int n)
{
    long long mx = 0, i = 0;
    stack<long long> st;
    while (i < n)
    {
        if (st.empty() or arr[st.top()] <= arr[i])
            st.push(i++);
        else
        {
            long long tp = st.top();
            st.pop();
            mx = max(mx, arr[tp] * (st.empty() ? i : i - st.top() - 1));
        }
    }
    while (!st.empty())
    {
        long long tp = st.top();
        st.pop();
        mx = max(mx, arr[tp] * (st.empty() ? i : i - st.top() - 1));
    }
    return mx;
}

int main()
{
    vector<int> heights = { 2, 1, 5, 6, 2, 3 };
    Solution s;
    cout<<s.largestRectangleAreaOptimal(heights)<<" ";
    return 0;
}