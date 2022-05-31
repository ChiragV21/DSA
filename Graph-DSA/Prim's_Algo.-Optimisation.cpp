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
    
    vector<int> parent(n,-1);  //O(n)
    vector<int> mst(n,false);  //O(n)
    vector<int> key(n,INT_MAX);  //O(n)
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    parent[0]=-1;
    key[0]=0;
    pq.push({0,0}); //node and index
    
    for(int edge=0;edge<n-1;edge++){
        
        int u=pq.top().second;  //find index-O(logn)
        pq.pop();
        mst[u]=true;
        
        for(auto it:adj[u]){        //Traversal a Graph-O(V+E)
            int v=it.first;
            int w=it.second;
            if(mst[v]==false and w<key[v]){
                parent[v]=u;
                pq.push({key[v],v});
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