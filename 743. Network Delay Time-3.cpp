// Floyd–Warshall
class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    int maxDelay = 99 * 100 + 1;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, maxDelay));

    for (auto &t : times)
      dist[t[0]][t[1]] = t[2];

    for (int i = 1; i <= n; ++i)
      dist[i][i] = 0;

    for (int k = 1; k <= n; ++k)
      for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int res = 0;
    for (int j = 1; j <= n; ++j)
      res = max(res, dist[k][j]);

    return res == maxDelay ? -1 : res;
  }
};