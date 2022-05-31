#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;        //where n is the no. of nodes and m is no. of edges
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1];    //Adjacency List

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    for(int i=1;i<=n;i++){
        cout<<i<<"->";
        for(auto j:adj[i]){
            cout<<j.first<<","<<j.second<<" ";
        }
        cout<<endl;
    }
    return 0;
}