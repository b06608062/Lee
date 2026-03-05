class Solution {
public:
  vector<vector<int>>
  findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges) {
    for (int i = 0; i < edges.size(); ++i) {
      edges[i].push_back(i);
    }

    vector<vector<vector<int>>> adj(n);
    for (const auto &edge : edges) {
      adj[edge[0]].push_back({edge[1], edge[2], edge[3]});
      adj[edge[1]].push_back({edge[0], edge[2], edge[3]});
    }

    auto minimax = [&](int src, int dst, int excludeIdx) -> int {
      vector<int> dist(n, INT_MAX);
      dist[src] = 0;

      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
      pq.push({0, src});

      while (!pq.empty()) {
        auto [maxW, u] = pq.top();
        pq.pop();
        if (u == dst)
          return maxW;

        for (const auto &neighbor : adj[u]) {
          int v = neighbor[0], weight = neighbor[1], edgeIdx = neighbor[2];
          if (edgeIdx == excludeIdx)
            continue;
          int newW = max(maxW, weight);
          if (newW < dist[v]) {
            dist[v] = newW;
            pq.push({newW, v});
          }
        }
      }
      return INT_MAX;
    };

    vector<int> critical, pseudo;
    for (const auto &edge : edges) {
      int u = edge[0], v = edge[1], w = edge[2], idx = edge[3];
      if (w < minimax(u, v, idx)) {
        critical.push_back(idx);
      } else if (w == minimax(u, v, -1)) {
        pseudo.push_back(idx);
      }
    }

    return {critical, pseudo};
  }
};