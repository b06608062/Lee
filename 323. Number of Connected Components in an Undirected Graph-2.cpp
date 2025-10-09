class Solution {
public:
  vector<vector<int>> adj;
  vector<int> vis;
  int countComponents(int n, vector<vector<int>> &edges) {
    adj = vector<vector<int>>(n);

    for (auto &e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vis = vector<int>(n, 0);
    int res = 0;
    for (int i = 0; i < n; ++i)
      if (!vis[i]) {
        res++;
        dfs(i);
      }

    return res;
  }

  void dfs(int u) {
    if (vis[u])
      return;

    vis[u] = 1;
    for (auto v : adj[u])
      dfs(v);
  }
};