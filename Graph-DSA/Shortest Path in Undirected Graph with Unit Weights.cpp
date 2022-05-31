#include<bits/stdc++.h>
using namespace std;
void ShortestPath(int n,vector<int> adj[],int src){
    queue<int> q;
    vector<int> dist(n,INT_MAX);
    dist[src]=0;
    q.push(src);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(dist[node]+1<dist[it]){
                dist[it]=dist[node]+1;
                q.push(it);
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }
}
int main(){
    int n,m,src;
    cin>>n>>m>>src;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ShortestPath(n,adj,src);
    return 0;
}