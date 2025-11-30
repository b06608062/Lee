class Solution {
public:
  const int INF = INT_MAX;
  using P = pair<int, int>;
  vector<vector<P>> adj;
  vector<bool> findAnswer(int n, vector<vector<int>> &edges) {
    int m = edges.size();
    adj.resize(n);
    for (auto &e : edges) {
      int u = e[0], v = e[1], w = e[2];
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }
    auto dist1 = dijk(n, 0);
    auto distN = dijk(n, n - 1);
    vector<bool> res(m, false);
    int D = dist1[n - 1];
    if (D == INF)
      return res;

    for (int i = 0; i < m; ++i) {
      auto &e = edges[i];
      int u = e[0], v = e[1], w = e[2];
      if ((dist1[u] != INF && distN[v] != INF &&
           dist1[u] + w + distN[v] == D) ||
          (dist1[v] != INF && distN[u] != INF && dist1[v] + w + distN[u] == D))
        res[i] = true;
    }

    return res;
  }

  vector<int> dijk(int n, int start) {
    vector<int> dist(n, INF);
    priority_queue<P, vector<P>, greater<P>> pq; // d, u

    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();
      if (d > dist[u])
        continue;
      for (auto &[v, w] : adj[u]) {
        if (d + w < dist[v]) {
          dist[v] = d + w;
          pq.push({d + w, v});
        }
      }
    }

    return dist;
  }
};