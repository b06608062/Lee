class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    int INF = 1e6;
    vector<int> dist(n, INF);

    dist[src] = 0;
    for (int i = 0; i <= k; ++i) {
      vector<int> prev = dist;
      for (auto &f : flights) {
        int u = f[0], v = f[1], p = f[2];
        dist[v] = min(dist[v], prev[u] + p);
      }
    }

    return dist[dst] == INF ? -1 : dist[dst];
  }
};