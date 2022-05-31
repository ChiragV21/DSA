#include<bits/stdc++.h>
using namespace std;
struct Node{
    int u,v,wt;
    Node(int first,int second,int weight){
        u=first;
        v=second;
        wt=weight;
    }
};

bool compare(Node a,Node b){
    return a.wt<b.wt;
}

int FindPar(int u,vector<int>& parent){
    if(u==parent[u])
        return u;
    return parent[u]=FindPar(parent[u],parent);
}

void unionn(int u,int v,vector<int>& parent,vector<int>& rank){
    u=FindPar(u,parent);
    v=FindPar(v,parent);

    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[v]<rank[u]){
        parent[v]=u;
    }
    else{                       //means both rank are equal
        parent[v]=u;
        rank[u]++;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<Node> edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back(Node(u,v,w));
    }

    sort(edges.begin(),edges.end(),compare);  //sort thr edges

    vector<int> parent(n+1);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }

    vector<int> rank(n+1,0);
    vector<pair<int,int>> mst;
    int cost=0;
    for(auto it:edges){
        if(FindPar(it.u,parent)!=FindPar(it.v,parent)){
            cost+=it.wt;
            mst.push_back({it.u,it.v});
            unionn(it.u,it.v,parent,rank);
        }
    }

    cout<<cost<<endl;
    for(auto it:mst){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}