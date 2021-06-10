#include<bits/stdc++.h>
using namespace std;

void dis(vector<vector<int>> &num)
{
    for (int i = 0; i < num.size(); i++)
    {
        cout << "[" << num[i][0] << "," << num[i][1] << "]" << endl;
    }
}
vector<vector<int>> merge(vector<vector<int>> &intervals)
{   
    vector<vector<int>> mergeIntervals;
    if(intervals.size() == 0){
        return mergeIntervals;
    }
    sort(intervals.begin(), intervals.end());

    vector<int> tempInterval= intervals[0];
    for(auto it: intervals){
        if(it[0]<=tempInterval[1]){
            tempInterval[1]= max(it[1],tempInterval[1]);
        }else{
            mergeIntervals.push_back(tempInterval);
            tempInterval= it;
        }
    }
    mergeIntervals.push_back(tempInterval);
    return mergeIntervals;
}
void mergeStack(vector<vector<int>> nums){
    sort(nums.begin(),nums.end());
    stack<pair<int,int>> s;
    s.push({nums[0][0],nums[0][1]});
    for(int i=1;i<nums.size();i++){
        int start1= s.top().first;
        int end1= s.top().second;
        int start2= nums[i][0];
        int end2= nums[i][1];
        if(end1< start2){
            s.push({start2,end2});
        }else{
            s.pop();
            end1= max(end1,end2);
            s.push({start1,end1});
        }
    }
    vector<vector<int>> new_Intervals;

    while (!s.empty())
    {
        new_Intervals.push_back({s.top().first,s.top().second});
        s.pop();
    }
    reverse(new_Intervals.begin(), new_Intervals.end());

    dis(new_Intervals);
    // while(!s.empty()){
    //     cout<<"["<<s.top().first<<","<<s.top().second<<"]"<<endl;
    //     s.pop();
    // }
}

int main()
{
    int n, i=0;
    cin>>n;
    vector<vector<int>> vi;
    for(i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        vi.push_back({x,y});
    }
    mergeStack(vi);
    vi= merge(vi);
    dis(vi);
    return 0;
}