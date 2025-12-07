// mark
// 1788
// Bitset + DAG + Topological Sort
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

    vector<bitset<1000>> anc(n);

    queue<int> q;
    for (int i = 0; i < n; ++i)
      if (indeg[i] == 0)
        q.push(i);

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : adj[u]) {
        anc[v].set(u);
        anc[v] |= anc[u];
        if (--indeg[v] == 0)
          q.push(v);
      }
    }

    vector<vector<int>> res(n);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (anc[i].test(j))
          res[i].push_back(j);

    return res;
  }
};
