// mark
// 1845
// Dijkstra 最短路徑 + 有限制更新條件

class Solution {
public:
  int minTime(int n, vector<vector<int>> &edges) {
    vector<vector<int>> adj(n);
    for (int i = 0; i < edges.size(); ++i)
      adj[edges[i][0]].push_back(i);

    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    using P = pair<int, int>; // t, u
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
      auto [t, u] = pq.top();
      pq.pop();
      if (t > dist[u])
        continue;
      if (u == n - 1)
        return t;
      for (auto idx : adj[u]) {
        auto &edge = edges[idx];
        int v = edge[1], s = edge[2], e = edge[3];
        if (t > e)
          continue;
        int mn_t = max(s, t) + 1;
        if (mn_t < dist[v]) {
          dist[v] = mn_t;
          pq.push({mn_t, v});
        }
      }
    }

    return -1;
  }
};