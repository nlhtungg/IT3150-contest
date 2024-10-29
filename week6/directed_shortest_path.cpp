#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> d(n, vector<int>(n, INF));

    for (int i = 0; i < n; ++i) {
        d[i][i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u - 1][v - 1] = w;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (d[i][k] < INF && d[k][j] < INF) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (d[i][j] == INF) {
                d[i][j] = -1;
            }
            cout << d[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
