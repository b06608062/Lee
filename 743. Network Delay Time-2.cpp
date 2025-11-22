// Bellman-Ford
class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    int maxDelay = 99 * 100 + 1;
    vector<int> dist(n + 1, maxDelay);

    dist[k] = 0;
    for (int i = 1; i < n - 1; ++i) {
      bool updated = false;
      for (auto &t : times) {
        int u = t[0], v = t[1];
        int cost = dist[u] + t[2];
        if (cost < dist[v]) {
          dist[v] = cost;
          updated = true;
        }
      }
      if (!updated)
        break;
    }

    int res = *max_element(dist.begin() + 1, dist.end());

    return res == maxDelay ? -1 : res;
  }
};