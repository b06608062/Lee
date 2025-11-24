class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    const int INF = 1e6;
    vector<vector<pair<int, int>>> adj(n);
    for (auto &f : flights) {
      int u = f[0], v = f[1], p = f[2];
      adj[u].push_back({v, p});
    }

    vector<vector<int>> best(n, vector<int>(k + 2, INF));
    using T = tuple<int, int, int>; // cost, node, steps
    priority_queue<T, vector<T>, greater<T>> pq;

    best[src][0] = 0;
    pq.push({0, src, 0});
    while (!pq.empty()) {
      auto [cost, u, steps] = pq.top();
      pq.pop();
      if (u == dst)
        return cost;
      if (steps == k + 1)
        continue;
      if (cost > best[u][steps])
        continue;
      for (auto [v, price] : adj[u]) {
        int ncost = cost + price;
        int nsteps = steps + 1;
        if (ncost < best[v][nsteps]) {
          best[v][nsteps] = ncost;
          pq.push({ncost, v, nsteps});
        }
      }
    }
    return -1;
  }
};