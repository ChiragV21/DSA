#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;        //where n is the no. of nodes and m is no. of edges
    cin>>n>>m;
    vector<vector<int>> adj(n+1,vector<int>(n+1));      //Adjacency Matrix
    // int adj[n+1][n+1];
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         adj[i][j]=0;
    //     }
    //     cout<<endl;
    // }

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}