#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// We use a pair to store {current_cost, node_index}
typedef pair<long long, int> pli;

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // 1-based indexing for nodes
    vector<long long> weight(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
    }

    // Use an Adjacency List instead of a Matrix to save memory
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Calculate initial cost for each node
    vector<long long> cost(n + 1, 0);
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            cost[u] += weight[v];
        }
    }

    // Min-heap to always fetch the node with the smallest current cost
    // greater<pli> ensures the smallest cost stays at the top
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    for (int u = 1; u <= n; u++) {
        pq.push({ cost[u], u });
    }

    vector<bool> deleted(n + 1, false);
    long long ans = 0;

    while (!pq.empty()) {
        auto [c, u] = pq.top();
        pq.pop();

        // If the node is already deleted, skip it.
        // We also skip outdated queue entries where the recorded cost is higher than the actual cost.
        if (deleted[u] || c > cost[u]) {
            continue;
        }

        // Delete the node and update the global answer
        deleted[u] = true;
        ans = max(ans, cost[u]);

        // Reduce the cost for all undeleted neighbors and push updates to the heap
        for (int v : adj[u]) {
            if (!deleted[v]) {
                cost[v] -= weight[u];
                pq.push({ cost[v], v });
            }
        }
    }

    cout << ans << "\n";

    return 0;
}