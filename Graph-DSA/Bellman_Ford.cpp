#include<bits/stdc++.h>
using namespace std;
struct node{
    int u,v,wt;
    node(int a,int b,int c){
        u=a;
        v=b;
        wt=c;
    }
};
int main(){
    int n,m;
    cin>>n>>m;
    vector<node> edges;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back(node(u,v,wt));
    }

    int inf = 10000000; 
    vector<int> dist(n,inf);
    int src=0;
    dist[src]=0;
    for(int i=1;i<=n-1;i++){
        for(auto it:edges){
            if(dist[it.u]+it.wt<dist[it.v]){
                dist[it.v]=dist[it.u]+it.wt;
            }
        }
    }

    int flag=0;
    //Negative Cycle Detection
    for(auto it:edges){
        if(dist[it.v]>dist[it.u]+it.wt){
            cout<<"Negative Cycle is Present"<<endl;
            flag=1;
            break;
        }
    }

    if(flag==0){
        for(int i=0;i<n;i++){
            cout<<dist[i]<<" ";
        }
    }
    return 0;
}