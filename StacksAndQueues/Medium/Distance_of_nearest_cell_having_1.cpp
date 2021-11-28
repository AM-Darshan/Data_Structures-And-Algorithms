#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

vector<vector<int>> nearest(vector<vector<int>> grid)
{
    int n= grid.size();
    int m= grid[0].size();
    vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
    queue<pair<int, int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1){
                ans[i][j] =0;
                q.push({i,j});
            }
        }
    }

    while(!q.empty()){
        int i= q.front().first;
        int j= q.front().second;
        int dx[4] = {-1, 0, +1, 0};
        int dy[4] = {0, +1, 0, -1};
        for(int k=0;k<4;k++){
            int nx = i+dx[k] , ny =j +dy[k];
            if(nx<0 || nx<0 || nx>=n || ny>=m) continue;
            if(ans[i][j]+1 < ans[nx][ny]){
                ans[nx][ny] = ans[i][j]+1;
                q.push({nx,ny});
            }
        }
        q.pop();
    }
    return ans;
}
int main()
{
    vector<vector<int>> grid = { {0, 1, 1, 0},
                                 {1, 1, 0, 0},
                                 {0, 0, 1, 1} 
                                };
    grid = nearest(grid);
    for(vector<int> i:grid){
        for(int j:i){
            cout<<j<<" "; 
        }
        cout<<endl;
    }                             
    return 0;
}