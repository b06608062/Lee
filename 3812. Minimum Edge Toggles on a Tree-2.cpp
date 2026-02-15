// mark
// 2179
// DFS 從葉節往上撥洋蔥

class Solution {
public:
  string start, target;
  vector<vector<pair<int, int>>> adj;
  vector<int> res;
  vector<int> minimumFlips(int n, vector<vector<int>> &edges, string start,
                           string target) {
    this->start = start, this->target = target;
    adj.resize(n);
    for (int i = 0; i < n - 1; ++i) {
      auto &e = edges[i];
      int u = e[0], v = e[1];
      adj[u].push_back({v, i});
      adj[v].push_back({u, i});
    }

    if (dfs(0, -1))
      return {-1};

    sort(res.begin(), res.end());
    return res;
  }

  bool dfs(int u, int p) {
    bool rev = start[u] != target[u];
    for (auto &[v, i] : adj[u]) {
      if (v != p && dfs(v, u)) {
        res.push_back(i);
        rev = !rev;
      }
    }
    return rev;
  }
};