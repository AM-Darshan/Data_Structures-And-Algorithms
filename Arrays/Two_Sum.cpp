#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    unordered_map<int, int> hash;
    vector<int> result;
    for (int i = 0; i < numbers.size(); i++)
    {
        int numberToFind = target - numbers[i];

        //if numberToFind is found in map, return them
        if (hash.find(numberToFind) != hash.end())
        {
            //+1 because indices are NOT zero based
            result.push_back(hash[numberToFind]);
            result.push_back(i);
            return result;
        }

        //number was not found. Put it in the map.
        hash[numbers[i]] = i;
    }
    return result;
}
int getPairsCount(int arr[], int n, int k) //gfg
{
    unordered_map<int, int> hash;
    int count=0;
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    for(int i=0;i<n;i++){
        count+= hash[k- arr[i]];
        if(k-arr[i] == arr[i]){
            count--;
        }
    }
    return count/2;
}
int main()
{
    int n,k;
    cin>>n;
    cin>>k;
    vector<int> arr,ans;
    int a[n];
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
        a[i]=x;
    }
    ans= twoSum(arr,k);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    cout<<getPairsCount(a,n,k);
    return 0;
}