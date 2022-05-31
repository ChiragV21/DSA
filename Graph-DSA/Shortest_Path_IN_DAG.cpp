#include<bits/stdc++.h>
using namespace std;
void solve(int node,vector<pair<int,int>> adj[],vector<int>& visited,stack<int>& st){
    visited[node]=1;
    for(auto it:adj[node]){
        if(!visited[it.first]){
            solve(it.first,adj,visited,st);
        }
    }
    st.push(node);
}
void ShortestPath(int n,vector<pair<int,int>> adj[],int src){
    stack<int> st;
    vector<int> visited(n,0);
    //topological order
    for(int i=0;i<n;i++){
        if(!visited[i]){
            solve(i,adj,visited,st);
        }
    }
    vector<int> dist(n,INT_MAX);
    dist[src]=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
         if(dist[node]!=INT_MAX){
            for(auto it:adj[node]){
                if(dist[node]+it.second<dist[it.first]){
                    dist[it.first]=dist[node]+it.second;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        if(dist[i]==INT_MAX)
            cout<<"INF"<<" ";
        else
            cout<<dist[i]<<" ";
    }
}
int main(){
    int n,m,src;
    cin>>n>>m>>src;
    vector<pair<int,int>> adj[n];
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }

    ShortestPath(n,adj,src);
    return 0;
}