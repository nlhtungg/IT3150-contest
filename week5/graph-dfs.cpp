#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u) {
    cout << u << " ";
    visited[u] = true;
    for(int v : adj[u]) {
        if(!visited[v]) {
            dfs(v);
        }
    }
}


int main() {
    int n, m; cin >> n >> m;
    adj.resize(n+1);
    visited.resize(n+1, false);

    while(m--){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
}