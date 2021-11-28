#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
//https://www.geeksforgeeks.org/first-negative-integer-every-window-size-k/

void printFirstNegativeInteger(int arr[], int n, int k)
{
    // A Double Ended Queue, Di that will store indexes of
    // useful array elements for the current window of size k.
    // The useful elements are all negative integers.
    deque<int> Di;

    /* Process first k (or first window) elements of array */
    int i;
    for (i = 0; i < k; i++)
        // Add current element at the rear of Di
        // if it is a negative integer
        if (arr[i] < 0)
            Di.push_back(i);

    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for (; i < n; i++)
    {
        // if Di is not empty then the element at the
        // front of the queue is the first negative integer
        // of the previous window
        if (!Di.empty())
            cout << arr[Di.front()] << " ";

        // else the window does not have a
        // negative integer
        else
            cout << "0"
                 << " ";

        // Remove the elements which are out of this window
        while ((!Di.empty()) && Di.front() < (i - k + 1))
            Di.pop_front(); // Remove from front of queue

        // Add current element at the rear of Di
        // if it is a negative integer
        if (arr[i] < 0)
            Di.push_back(i);
    }

    // Print the first negative
    // integer of last window
    if (!Di.empty())
        cout << arr[Di.front()] << " ";
    else
        cout << "0"
             << " ";
}


vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{

    vector<long long> ans;
    queue<long long> q;
    for (int i = 0; i < K - 1; i++)
    {
        if (A[i] < 0)
            q.push(A[i]);
    }

    for (int i = K - 1; i < N; i++)
    {
        if (A[i] < 0)
            q.push(A[i]);
        if (!q.empty())
        {
            ans.push_back(q.front());
            if (q.front() == A[i - K + 1])
                q.pop();
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}

int main()
{
    long long int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    long long int n = sizeof(arr) / sizeof(arr[0]);
    long long int k = 3;
    vector<long long> res= printFirstNegativeInteger(arr, n, k);
    for(int x:res){
        cout<<x<<" ";
    }
    return 0;
}