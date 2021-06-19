#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums) //Moore voting algorithm
{
    int count=0;
    int candidate=0,i;
    for(int num: nums){
        if(count == 0){
            candidate= num;
        }
        if(candidate == num ) count+=1;
        else count-=1;
    }
    return candidate;
}

int majorityElement1(vector<int> &nums)
{
    unordered_map<int, int> m;
    int size= nums.size();
    for (int i = 0; i < size; i++)
        m[nums[i]]++;
    int count = 0;
    for (auto i : m)
    {
        if (i.second > size / 2)
        {
            count = 1;
            return i.first;
            break;
        }
    }
    if (count == 0)
        cout << "No Majority element" << endl;

    return -1;
    // sort(nums.begin(),nums.end());
    // return nums[nums.size()/2];
}
int main()
{
    int n,i;
    cin>>n;
    vector<int> arr;
    for(i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout << majorityElement(arr)<<"\n";
    cout<<majorityElement1(arr);
    return 0;
}