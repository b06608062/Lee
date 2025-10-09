class Solution {
public:
  vector<vector<int>> adj;
  vector<int> vis;
  bool validTree(int n, vector<vector<int>> &edges) {
    adj = vector<vector<int>>(n);

    for (auto &e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vis = vector<int>(n, 0);
    if (!dfs(0, -1))
      return false;

    for (int i = 0; i < n; ++i)
      if (vis[i] == 0)
        return false;

    return true;
  }

  bool dfs(int u, int parent) {
    if (vis[u] == 1)
      return false;

    vis[u] = 1;
    for (auto v : adj[u]) {
      if (v == parent)
        continue;
      if (!dfs(v, u))
        return false;
    }

    return true;
  }
};