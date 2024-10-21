#include<bits/stdc++.h>

using namespace std;

vector<int> parent, rank_;
vector<pair<int, pair<int, int>>> edges;

int find_set(int u) {
    if(parent[u] == u) return u;
    return parent[u] = find_set(parent[u]);
}

void union_set(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if(u != v) {
        if(rank_[u] < rank_[v]) swap(u, v);
        parent[v] = u;
        if(rank_[u] == rank_[v]) rank_[u]++;
    }
}

int main() {
    int n, m; cin >> n >> m;
    parent.resize(n+1);
    rank_.resize(n+1);
    for(int i=1;i<=n;i++) {
        parent[i] = i;
        rank_[i] = 0;
    }

    while(m--) {
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }

    sort(edges.begin(), edges.end());

    int mst = 0;
    for(auto edge : edges) {
        int w = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(find_set(u) != find_set(v)) {
            mst += w;
            union_set(u, v);
        }
    }

    cout << mst << endl;
}