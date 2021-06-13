#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,m;//verteces,edges
    cin>>n>>m;
    vector<int> adj[n+1]; //adjacency list
    int adjMat[n + 1][n + 1]; //adjacency matrix
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        //adjMat[u][v]=1;
        //adjMat[v][u]=1;
    }
    return 0;
}