#include<bits/stdc++.h>
using namespace std;
bool solve(int x,vector<int> adj[],vector<int>& color){
    queue<int> q;
    q.push(x);
    color[x]=1;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(color[it]==-1){
                color[it]=1-color[node];
                q.push(it);
            }
            else if(color[it]==color[node]){
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(int n,vector<int> adj[]){
    vector<int> color(n+1,-1);
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            if(!solve(i,adj,color))
                return false;
        }
    }
    return true;
}
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n,m;
        cin>>n>>m;
        vector<int> adj[n+1];
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if(isBipartite(n,adj))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}