class Solution {
public:
  vector<vector<int>> adj;
  vector<bool> vis;
  unordered_set<int> uset;
  int mark;
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int n = edges.size();
    adj.resize(n + 1);
    vis.resize(n + 1, false);
    for (auto &e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    mark = -1;
    dfs(1, -1);

    for (int i = n - 1; i >= 0; --i) {
      int u = edges[i][0], v = edges[i][1];
      if (uset.count(u) && uset.count(v)) {
        return {u, v};
      }
    }
    return {};
  }

private:
  bool dfs(int u, int p) {
    if (vis[u]) {
      mark = u;
      return true;
    }
    vis[u] = true;
    for (int v : adj[u]) {
      if (v == p)
        continue;
      if (dfs(v, u)) {
        if (mark != -1)
          uset.insert(u);
        if (u == mark) {
          mark = -1;
          return false;
        }
        return true;
      }
    }
    return false;
  }
};