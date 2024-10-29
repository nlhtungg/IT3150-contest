#include<bits/stdc++.h>

using namespace std;

bool bfs(int s, int t, const vector<vector<int>>& capacity, 
         vector<vector<int>>& residual, vector<int>& parent) {
    int n = capacity.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && residual[u][v] > 0) {
                q.push(v);
                visited[v] = true;
                parent[v] = u;

                if (v == t) {
                    return true;
                }
            }
        }
    }
    return false;
}

int solve(int s, int t, vector<vector<int>>& capacity) {
    int n = capacity.size();
    vector<vector<int>> residual = capacity;
    vector<int> parent(n);
    int maxFlow = 0;
    while (bfs(s, t, capacity, residual, parent)) {
        int pathFlow = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residual[u][v]);
        }
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            residual[u][v] -= pathFlow;
            residual[v][u] += pathFlow;
        }
        maxFlow += pathFlow;
    }
    return maxFlow;
}

int main() {
    int N, M;
    cin >> N >> M;

    int s, t;
    cin >> s >> t;
    s--; t--;
    vector<vector<int>> capacity(N, vector<int>(N, 0));
    for (int i = 0; i < M; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        capacity[u][v] += c;
    }
    int maxFlow = solve(s, t, capacity);
    cout << maxFlow << endl;
    return 0;
}
