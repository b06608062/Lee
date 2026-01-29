class Solution {
public:
  long long minimumCost(string source, string target, vector<char> &original,
                        vector<char> &changed, vector<int> &cost) {
    int n = source.size(), m = original.size();
    const int INF = INT_MAX / 2;
    // APSP
    // source -> target
    vector dist(26, vector<int>(26, INF));
    for (int i = 0; i < 26; ++i) {
      dist[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
      int u = original[i] - 'a', v = changed[i] - 'a', c = cost[i];
      dist[u][v] = min(dist[u][v], c);
    }

    for (int k = 0; k < 26; ++k) {
      for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }

    long long res = 0;
    for (int i = 0; i < n; ++i) {
      int u = source[i] - 'a', v = target[i] - 'a';
      if (dist[u][v] == INF) {
        return -1;
      }
      res += dist[u][v];
    }

    return res;
  }
};