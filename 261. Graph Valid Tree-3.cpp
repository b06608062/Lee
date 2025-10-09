class Solution {
public:
  bool validTree(int n, vector<vector<int>> &edges) {
    vector<vector<int>> adj(n);
    vector<int> vis(n, 0);

    for (auto &e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    queue<pair<int, int>> q; // u, parent
    q.push({0, -1});
    vis[0] = 1;
    while (!q.empty()) {
      auto [u, parent] = q.front();
      q.pop();
      for (auto v : adj[u]) {
        if (v == parent)
          continue;
        if (vis[v])
          return false;
        vis[v] = 1;
        q.push({v, u});
      }
    }

    for (int i = 0; i < n; ++i)
      if (vis[i] == 0)
        return false;

    return true;
  }
};