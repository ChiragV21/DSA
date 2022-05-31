#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n];
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int parent[n],mst[n],key[n];
    for(int i=0;i<n;i++){
        parent[i]=-1;
        mst[i]=false;
        key[i]=INT_MAX;
    }

    parent[0]=-1;
    key[0]=0;

    for(int edges=0;edges<n-1;edges++){
        int mini=INT_MAX;
        int u;
        for(int i=0;i<n;i++){
            if(mst[i]==false and key[i]<mini){
                mini=key[i];
                u=i;
            }
        }

        mst[u]=true;

        for(auto it:adj[u]){
            int v=it.first;
            int w=it.second;
            if(mst[v]==false and w<key[v]){
                parent[v]=u;
                key[v]=w;
            }
        }
    }

    int ans=0;
    for(int i=0;i<n;i++){
        ans+=key[i];
    }
    cout<<ans<<endl;
    return 0;
} 
