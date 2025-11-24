class Solution {
public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);
    for (auto &e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v);
      indeg[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; ++i)
      if (indeg[i] == 0)
        q.push(i);

    vector<set<int>> parents(n);

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      auto &pu = parents[u];
      for (auto v : adj[u]) {
        auto &pv = parents[v];
        pv.insert(u);
        for (auto pp : pu)
          pv.insert(pp);
        if (--indeg[v] == 0)
          q.push(v);
      }
    }

    vector<vector<int>> res(n);
    for (int i = 0; i < n; ++i)
      res[i].insert(res[i].begin(), parents[i].begin(), parents[i].end());

    return res;
  }
};