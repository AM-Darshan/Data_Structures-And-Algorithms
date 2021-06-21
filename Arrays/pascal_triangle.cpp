#include<bits/stdc++.h>
using namespace std;
//Given an integer numRows, return the first numRows of Pascal's triangle. 
vector<vector<int>> generate(int numRows)
{
    vector<vector<int> > res(numRows);
    for(int i=0;i<numRows;i++){
        res[i].resize(i+1);
        res[i][0]= res[i][i]=1;

        for(int j=1;j<i;j++){
            res[i][j]= res[i-1][j-1] + res[i-1][j]; 
        }
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> res= generate(n);
    for (int i = 0; i < res.size(); i++)
    {
        cout<<"[";
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout <<"],";
    }
    return 0;
}