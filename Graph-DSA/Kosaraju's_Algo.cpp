#include<bits/stdc++.h>
using namespace std;
void solve(int node,vector<int> adj[],vector<int>& visited,stack<int>& st){
    visited[node]=true;
    for(auto it:adj[node]){
        if(!visited[it]){
            solve(it,adj,visited,st);
        }
    }
    st.push(node);
}

void dfs(int node,vector<int> transpose[],vector<int>& visited){
    visited[node]=1;
    cout<<node<<" ";
    for(auto it:transpose[node]){
        if(!visited[it]){
            dfs(it,transpose,visited);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    //step-1: Do Topological sort:sort all the nodes of finishing time 
    stack<int> st;
    vector<int> visited(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            solve(i,adj,visited,st);
        }
    }

    //step-2: Transpose of a Graph:You will not going to apart from SCC
    vector<int> transpose[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
        for(auto it:adj[i]){
            transpose[it].push_back(i);
        }
    }

    //step-3: Perform DFS on Transpose Graph
    int cnt=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!visited[node]){
            cnt++;
            dfs(node,transpose,visited);
            cout<<endl;
        }
    }
    cout<<cnt<<endl;
    return 0;
}