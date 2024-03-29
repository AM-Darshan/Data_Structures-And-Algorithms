#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> res;
    if(nums.empty())
        return res;
    int n= nums.size();
    sort(nums.begin(),nums.end());

    for(int i=0;i<n;i++){
        
        for(int j=i+1;j<n;j++){

            int target2= target - nums[j] - nums[i];

            int front = j+1;
            int back= n-1;

            while(front< back){
                int two_sum= nums[front]+ nums[back];
                
                if(two_sum < target2)
                    front++;
                else if(two_sum > target2)
                    back--;
                else{
                    vector<int> quadruplet(4,0);
                    quadruplet[0]= nums[i];
                    quadruplet[1]= nums[j];
                    quadruplet[2]= nums[front];
                    quadruplet[3]= nums[back];
                    res.push_back(quadruplet);

                    while(front<back && nums[front] == quadruplet[2]) ++front;

                    while(front< back && nums[back] == quadruplet[3]) --back;
                }
            }
            while(j+1<n && nums[j+1] == nums[j] ) ++j;
        }
        while (i + 1 < n && nums[i + 1] == nums[i]) ++i;
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
    int t;
    cin >> t;
    vector< vector<int> > ans = fourSum(a,t);
    for (int i = 0; i < ans.size(); i++){
       for(int j=0; j< ans[i].size();j++){
            cout<<ans[i][j]<<" ";
       }
       cout<<",";
    }
    return 0;
}