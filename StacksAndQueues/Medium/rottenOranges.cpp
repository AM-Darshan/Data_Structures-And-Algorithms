#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1
//https://leetcode.com/problems/rotting-oranges/

int orangesRotting(vector<vector<int>> &grid)
{
    if(grid.empty()) return 0;
    int n= grid.size();
    int m= grid[0].size();
    queue<pair<int,int>> rotten;
    int days=0,total=0,cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]!=0) total++;
            if(grid[i][j] == 2) rotten.push({i,j});
        }
    }
    int dx[4] = {-1,0,+1,0};
    int dy[4] = {0,+1,0,-1};
    while(!rotten.empty()){
        int k = rotten.size();
        cnt+= k;
        while(k--){
            int x = rotten.front().first, y = rotten.front().second;
            rotten.pop();
            for(int i=0;i<4;i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]!=1) continue;
                grid[nx][ny] =2;
                rotten.push({nx,ny});
            } 
        }
        if(!rotten.empty()) days++;
    }
    if(total == cnt)
        return days;
    else
        return -1;
}
int main()
{
    vector<vector<int>> grid= {{2,1,1},{1,1,0},{0,1,1}};
    cout<<orangesRotting(grid);
    return 0;
}