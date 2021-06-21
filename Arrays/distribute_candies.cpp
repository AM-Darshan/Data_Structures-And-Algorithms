#include<bits/stdc++.h>
using namespace std;

int distributeCandies(vector<int> &candyType)
{
    int n= candyType.size();
    int n2= n/2,i,maxcan=1;
    sort(candyType.begin(),candyType.end());
    for(i=1;i<n;i++){
        if(candyType[i-1] != candyType[i]){
            maxcan++;
        }
    }
    return min(maxcan, n2);
    //return min(unordered_set<int>(begin(candyType), end(candyType)).size(), candyType.size() / 2);
}

int distributeCandies1(vector<int> &candyType) // tle error
{
    int uniqueCandy=0;
    int n= candyType.size();

    for(int i=0;i<n;i++){
        bool isunique=true;
        for(int j=0;j<i;j++){
            if(candyType[i] == candyType[j]){
                isunique= false;
                break;
            }
        }
        if(isunique)
            uniqueCandy++;
    }
    return min(uniqueCandy, n/2);
}
int main()
{
    int n, i;
    cin>> n;
    vector<int> arr;
    for (i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout<<distributeCandies(arr);
    return 0;
}