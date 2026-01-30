// mark
// 2696
// APSP + 字符串 DP + 內層枚舉候選 strlen 剪枝

class Solution {
public:
  long long minimumCost(string source, string target, vector<string> &original,
                        vector<string> &changed, vector<int> &cost) {
    // APSP
    // str 2 str
    // dp
    const long long INF = LLONG_MAX / 2;
    int n = source.size(), m = original.size();
    unordered_map<string, int> s2i;
    vector<string> arr;
    int idx = 0;
    for (auto &s : original) {
      if (!s2i.count(s)) {
        s2i[s] = idx++;
        arr.push_back(s);
      }
    }
    for (auto &s : changed) {
      if (!s2i.count(s)) {
        s2i[s] = idx++;
        arr.push_back(s);
      }
    }
    int sz = arr.size(); // 最多 100 種長度
    vector dist(sz, vector<long long>(sz, INF));
    for (int i = 0; i < sz; ++i) {
      dist[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
      int u = s2i[original[i]], v = s2i[changed[i]], c = cost[i];
      dist[u][v] = min(dist[u][v], 1ll * c);
    }

    for (int k = 0; k < sz; ++k) {
      for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }

    set<int> sset;
    for (auto &s : arr) {
      sset.insert(s.size());
    }

    vector<long long> dp(n + 1, INF);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (source[i] == target[i]) {
        dp[i] = dp[i + 1];
      }
      for (auto l : sset) {
        if (i + l > n)
          break;
        auto s = source.substr(i, l), t = target.substr(i, l);
        if (s2i.count(s) && s2i.count(t)) {
          int u = s2i[s], v = s2i[t];
          dp[i] = min(dp[i], dp[i + l] + dist[u][v]);
        }
      }
    }

    return dp[0] == INF ? -1 : dp[0];
  }
};