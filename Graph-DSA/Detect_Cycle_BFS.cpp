#include<bits/stdc++.h>
using namespace std;
bool Cycle(int x,vector<int>& visited,vector<int> adj[],int V){
    queue<pair<int,int>> q;
    visited[x]=true;
    q.push({x,-1});
    while(!q.empty()){
        int node=q.front().first;
        int par=q.front().second;
        q.pop();
        for(auto it:adj[node]){
            if(!visited[it]){
                visited[it]=true;
                q.push({it,node});
            }
            else if(it!=par){
                return true;
            }
        }
    }
    return false;
}
bool isCycle(int V,vector<int> adj[]){
    vector<int> visited(V+1,0);
    for(int i=1;i<=V;i++){
        if(!visited[i]){
            if(Cycle(i,visited,adj,V))
                return true;
        }
    }
    return false;
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

    if(isCycle(n,adj))
        cout<<"Cycle Present"<<endl;
    else    
        cout<<"No Cycle Present"<<endl;

    return 0;
}