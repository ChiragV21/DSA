#include<bits/stdc++.h>
using namespace std;
void solve(int node,vector<int>& visited,vector<int> adj[],vector<int>& dfs){
    dfs.push_back(node);
    visited[node]=1;
    for(auto it:adj[node]){
        if(!visited[it]){
            solve(it,visited,adj,dfs);
        }
    }
}
vector<int> dfsOfGraph(int n,vector<int> adj[]){
    vector<int> dfs;
    vector<int> visited(n+1,0);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            solve(i,visited,adj,dfs);
        }
    }
    return dfs;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans=dfsOfGraph(n,adj);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}