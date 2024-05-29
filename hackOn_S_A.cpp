#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isFeasible(int x, int y, vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    q.push(x);
    visited[x] = true;
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v == y) return true;
        for (int u : adj[v]) {
            if (!visited[u]) {
                q.push(u);
                visited[u] = true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        if (isFeasible(x, y, adj)) {
            cout << "YO" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}