#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> hashSet(nums.begin(),nums.end());
    // for(int num: nums){
    //     hashSet.insert(num);
    // }
    int longestStreak=0;

    for(int num: nums){
        if(!hashSet.count(num-1)){
            int currentNum= num;
            int currentStreak= 1;
            while(hashSet.count(currentNum+1)){
                currentNum+=1;
                currentStreak+=1;
            }

            longestStreak= max(longestStreak, currentStreak);
        }
    }
    return longestStreak;

   /* unordered_set<int> S;
    int ans = 0;

    // Hash all the array elements
    for (int i = 0; i < n; i++)
        S.insert(arr[i]);

    // check each possible sequence from
    // the start then update optimal length
    for (int i = 0; i < n; i++)
    {
        // if current element is the starting
        // element of a sequence
        if (S.find(arr[i] - 1) == S.end())
        {
            // Then check for next elements
            // in the sequence
            int j = arr[i];
            while (S.find(j) != S.end())
                j++;

            // update  optimal length if
            // this length is more
            ans = max(ans, j - arr[i]);
        }
    }
    return ans;*/
}

int longest2(vector<int> &num)
{
    unordered_set<int> record(num.begin(), num.end());
    int res = 0;
    for (int n : num)
    {
        if (record.find(n) == record.end())
            continue;
        record.erase(n);
        int prev = n - 1, next = n + 1;
        while (record.find(prev) != record.end())
            record.erase(prev--);
        while (record.find(next) != record.end())
            record.erase(next++);
        res = max(res, next - prev - 1);
    }
    return res;
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
    cout<<longestConsecutive(a)<<endl;
    cout<<longest2(a);
    return 0;
}