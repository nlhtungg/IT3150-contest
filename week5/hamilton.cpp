#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

int main() {
    int t; cin >> t;
    while(t--){
        bool check = true;
        int n, m; cin >> n >> m;
        adj.resize(n+1);
        visited.resize(n+1, false);
        
        while(m--){
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=1;i<=n;i++){
            if(adj[i].size() < n/2) check = false;
        }
        if(check==true) cout << 1 << endl;
        else cout << 0 << endl;
    }
}