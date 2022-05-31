#include <bits/stdc++.h>
using namespace std;
void solve(int node, vector<int> adj[], vector<int> &visited, stack<int> &st)
{
    visited[node] = 1;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            solve(it, adj, visited, st);
        }
    }
    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    stack<int> st;
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            solve(i, adj, visited, st);
        }
    }

    vector<int> ans;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        ans.push_back(node);
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> ans=topoSort(n,adj);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}