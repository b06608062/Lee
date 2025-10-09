// Dijkstra
class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    using P = pair<int, int>;
    vector<vector<P>> adj(n + 1); // u, (v, t)
    for (auto &t : times)
      adj[t[0]].push_back({t[1], t[2]});

    vector<int> dist(n + 1, INT_MAX / 2);

    // min heap
    priority_queue<P, vector<P>, greater<P>> pq; // cost, u

    dist[k] = 0;
    pq.push({0, k});
    while (!pq.empty()) {
      auto [cost, u] = pq.top();
      pq.pop();
      if (cost > dist[u])
        continue;
      for (auto [v, t] : adj[u])
        if (cost + t < dist[v]) {
          dist[v] = cost + t;
          pq.push({dist[v], v});
        }
    }

    int res = 0;
    for (int i = 1; i <= n; ++i)
      res = max(res, dist[i]);

    return res == INT_MAX / 2 ? -1 : res;
  }
};