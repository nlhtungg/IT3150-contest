#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

int dijkstra(int n, vector<vector<pair<int, int>>>& graph, int s, int t) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (u == t) return d;
        if (d > dist[u]) continue;

        for (auto [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return -1;
}

int main() {
    int n, m, u, v, w, s, t;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);

    while (m--) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    cin >> s >> t;
    cout << dijkstra(n, graph, s, t) << endl;
    return 0;
}
