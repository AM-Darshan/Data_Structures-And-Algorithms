#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &arr) //Boyer Moore voting algorithm
//can have atmost 2 majority elements 
{
    int count1 = 0, count2 = 0;
    int first = INT_MAX, second = INT_MAX;
    int n=arr.size();
    for (int i = 0; i < n; i++)
    {

        // if this element is previously seen,
        // increment count1.
        if (first == arr[i])
            count1++;

        // if this element is previously seen,
        // increment count2.
        else if (second == arr[i])
            count2++;

        else if (count1 == 0)
        {
            count1++;
            first = arr[i];
        }

        else if (count2 == 0)
        {
            count2++;
            second = arr[i];
        }

        // if current element is different from
        // both the previously seen variables,
        // decrement both the counts.
        else
        {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;

    // Again traverse the array and find the
    // actual counts.
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == first)
            count1++;

        else if (arr[i] == second)
            count2++;
    }
    vector<int> res;
    if (count1 > n / 3)
       res.push_back(first);
    if (count2 > n / 3)
       res.push_back(second);

    return res;
}


vector<int> majorityElement1(vector<int> &nums)
{
    vector<int> res;
    int size= nums.size();
    unordered_map<int, int> m;
    for (int i = 0; i < size; i++)
        m[nums[i]]++;
    int count = 0;
    for (auto i : m)
    {
        if (i.second > size / 3)
        {
            count = 1;
            res.push_back(i.first);
        }
    }
    if (count == 0)
        cout << "No Majority element" << endl;
    return res;
}
int main()
{
    int n, i;
    cin >> n;
    vector<int> a;
    for (i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    vector<int> ans= majorityElement(a);
    for(int j:ans) cout<<j<<" ";
    cout<<"\n";
    ans= majorityElement1(a);
    for (int j : ans)
        cout << j << " ";
    return 0;
}