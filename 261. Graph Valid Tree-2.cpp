class Solution {
public:
  vector<vector<int>> adj;
  vector<int> vis;
  bool validTree(int n, vector<vector<int>> &edges) {
    if (edges.size() != n - 1)
      return false;
    adj.resize(n);
    vis.assign(n, 0);
    for (auto &e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    dfs(0);
    for (int i = 0; i < n; ++i)
      if (!vis[i])
        return false;

    return true;
  }

  void dfs(int u) {
    if (vis[u])
      return;
    vis[u] = 1;
    for (auto v : adj[u])
      dfs(v);
  }
};
