#include<bits/stdc++.h>
using namespace std;

int countOccurence(vector<int> &nums, int n, int k) // GFG count no:of elements with n/k occurances 
{
    int i, count = 0;
    unordered_map<int, int> mp;
    for (i = 0; i < n; i++)
        mp[nums[i]]++;

    int x = n / k;
    for (auto number : mp)
    {
        if (number.second > x)
            count++;
    }
    return count;
}
struct eleCount
{
    int e; // Element
    int c; // Count
};

// Prints elements with more
// than n/k occurrences in arr[]
// of size n. If there are no
// such elements, then it prints
// nothing.
void moreThanNdK(vector<int> &arr, int n, int k)  //GFG number,count of n/k occurances
{
    // k must be greater than
    // 1 to get some output
    if (k < 2)
        return;

    /* Step 1: Create a temporary
       array (contains element
       and count) of size k-1.
       Initialize count of all
       elements as 0 */
    struct eleCount temp[k - 1];
    for (int i = 0; i < k - 1; i++)
        temp[i].c = 0;

    /* Step 2: Process all
      elements of input array */
    for (int i = 0; i < n; i++)
    {
        int j;

        /* If arr[i] is already present in
           the element count array,
           then increment its count
         */
        for (j = 0; j < k - 1; j++)
        {
            if (temp[j].e == arr[i])
            {
                temp[j].c += 1;
                break;
            }
        }

        /* If arr[i] is not present in temp[] */
        if (j == k - 1)
        {
            int l;

            /* If there is position available
              in temp[], then place arr[i] in
              the first available position and
              set count as 1*/
            for (l = 0; l < k - 1; l++)
            {
                if (temp[l].c == 0)
                {
                    temp[l].e = arr[i];
                    temp[l].c = 1;
                    break;
                }
            }

            /* If all the position in the
               temp[] are filled, then decrease
               count of every element by 1 */
            if (l == k - 1)
                for (l = 0; l < k - 1; l++)
                    temp[l].c -= 1;
        }
    }

    /*Step 3: Check actual counts of
     * potential candidates in temp[]*/
    for (int i = 0; i < k - 1; i++)
    {
        // Calculate actual count of elements
        int ac = 0; // actual count
        for (int j = 0; j < n; j++)
            if (arr[j] == temp[i].e)
                ac++;

        // If actual count is more than n/k,
        // then print it
        if (ac > n / k)
            cout << "Number:" << temp[i].e
                 << " Count:" << ac << endl;
    }
}
int main()
{
    int n,k,i;
    cin>>n>>k;
    vector<int> arr;
    for (i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout<<countOccurence(arr,n,k)<<"\n";
    moreThanNdK(arr,n,k);
    cout<<"\n";
    // vector<int> ans = topKFrequent1(arr,k);
    // for(auto i:ans) 
    //     cout<<i<<" ";
    return 0;
}