class Solution {
public:
  int minCost(int n, vector<vector<int>> &edges) {
    const int INF = INT_MAX / 2;
    // dijk
    // in out
    vector<vector<pair<int, int>>> adj(n);
    for (auto &e : edges) {
      int u = e[0], v = e[1], w = e[2];
      adj[u].push_back({v, w});
      adj[v].push_back({u, 2 * w});
    }

    vector<int> dist(n, INF);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, 0});

    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();
      if (d > dist[u])
        continue;
      for (auto &[v, w] : adj[u]) {
        int nd = d + w;
        if (nd < dist[v]) {
          dist[v] = nd;
          pq.push({nd, v});
        }
      }
    }

    return dist[n - 1] == INF ? -1 : dist[n - 1];
  }
};