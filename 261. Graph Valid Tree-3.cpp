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

    queue<int> q;
    vis[0] = 1;
    q.push(0);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto v : adj[u]) {
        if (vis[v])
          continue;
        vis[v] = 1;
        q.push(v);
      }
    }

    for (int i = 0; i < n; ++i)
      if (!vis[i])
        return false;

    return true;
  }
};
