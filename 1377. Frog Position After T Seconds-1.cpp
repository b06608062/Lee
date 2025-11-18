class Solution {
public:
  vector<vector<int>> adj;
  double res = 0.0;
  double frogPosition(int n, vector<vector<int>> &edges, int t, int target) {
    adj.resize(n + 1);
    for (auto &e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    dfs(1, 1.0, t, target, 0);

    return res;
  }

  void dfs(int i, double p, int t, int target, int parent) {
    int sz = adj[i].size() - (parent > 0 ? 1 : 0);

    if (i == target) {
      if (t == 0 || sz == 0)
        res = p;
      return;
    }

    if (t == 0)
      return;

    for (auto j : adj[i]) {
      if (j != parent)
        dfs(j, p / sz, t - 1, target, i);
    }
  }
};