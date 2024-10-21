#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void bfs(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while(!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for(int v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
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

    for(int i=1;i<=n;i++){
        sort(adj[i].begin(), adj[i].end());
    }

    for(int i=1;i<=n;i++){
        if(!visited[i]) {
            bfs(i);
        }
    }
}