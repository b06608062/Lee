class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int n = edges.size();
    vector<int> ind(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    for (auto &edge : edges) {
      int u = edge[0], v = edge[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
      ind[u]++;
      ind[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
      if (ind[i] == 1)
        q.push(i);

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      ind[u]--;
      for (auto v : adj[u])
        if (--ind[v] == 1)
          q.push(v);
    }

    for (int i = n - 1; i >= 0; --i) {
      int u = edges[i][0], v = edges[i][1];
      if (ind[u] == 2 && ind[v])
        return {u, v};
    }
    return {};
  }
};