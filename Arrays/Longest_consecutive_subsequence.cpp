#include<bits/stdc++.h>
using namespace std;

int longestConsecutiveoptimal(vector<int> &nums){
    if (nums.size() == 0)
    {
        return 0;
    }
    priority_queue<int, vector<int>, greater<int> > pq;
    int i,n =nums.size(), count=1, max=1;
    for(i=0;i<n;i++){
        pq.push(nums[i]);
    }
    int prev= pq.top();
    pq.pop();

    while(!pq.empty()){
        if(pq.top() - prev >1){
            count=1;
            prev= pq.top();
            pq.pop();
        }else if(pq.top()- prev ==0){
            prev= pq.top();
            pq.pop();
        }else{
            count++;
            prev= pq.top();
            pq.pop();
        }

        if(max< count){
            max= count;
        }
    }

    return max;
}
int longestConsecutive(vector<int> &num)
{
    if (num.size() == 0)
    {
        return 0;
    }
    // unordered_set<int> record(num.begin(), num.end());
    // int res = 1;
    // for (int n : num)
    // {
    //     if (record.find(n) == record.end())
    //         continue;
    //     record.erase(n);
    //     int prev = n - 1, next = n + 1;
    //     while (record.find(prev) != record.end())
    //         record.erase(prev--);
    //     while (record.find(next) != record.end())
    //         record.erase(next++);
    //     res = max(res, next - prev - 1);
    // }
    // return res;

    unordered_set<int> S;
    int ans = 0,n= num.size();
    // Hash all the array elements
    for (int i = 0; i < n; i++)
        S.insert(num[i]);

    // check each possible sequence from
    // the start then update optimal length
    for (int i = 0; i < n; i++)
    {
        // if current element is the starting
        // element of a sequence
        if (S.find(num[i] - 1) == S.end())
        {
            // Then check for next elements
            // in the sequence
            int j = num[i];
            while (S.find(j) != S.end())
                j++;

            // update  optimal length if
            // this length is more
            ans = max(ans, j - num[i]);
        }
    }
    return ans;
}
int longestbruteforce(vector<int> &nums)
{
    int ans=0,count=0,i;
    int n= nums.size();
    sort(nums.begin(),nums.end());
    vector<int> vi;
    vi.push_back(nums[0]);
    for(i=1;i<n;i++){
        if(nums[i]!=nums[i-1]){
            vi.push_back(nums[i]);
        }
    }
    for(int i=0;i<=vi.size();i++){
        if(i>0 && nums[i] == nums[i-1]+1)
            count++;
        else
            count=1;
        ans= max(ans,count);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout<<longestbruteforce(arr)<<"\n";
    cout<<longestConsecutive(arr)<<"\n";
    cout<<longestConsecutiveoptimal(arr);
    return 0;
}