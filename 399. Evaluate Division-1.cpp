class Solution {
public:
  unordered_map<string, unordered_map<string, double>> adj;
  vector<double> calcEquation(vector<vector<string>> &equations,
                              vector<double> &values,
                              vector<vector<string>> &queries) {
    int n = equations.size();
    for (int i = 0; i < n; ++i) {
      string &u = equations[i][0], &v = equations[i][1];
      double val = values[i];
      adj[u][v] = val;
      adj[v][u] = 1 / val;
    }

    vector<double> res;
    for (auto &q : queries) {
      string &u = q[0], &t = q[1];
      if (!adj.count(u) || !adj.count(t)) {
        res.push_back(-1.0);
        continue;
      }
      unordered_set<string> vis;
      res.push_back(dfs(u, t, vis));
    }

    return res;
  }

  double dfs(const string &u, string &t, unordered_set<string> &vis) {
    if (vis.count(u))
      return -1.0;
    vis.insert(u);
    if (u == t)
      return 1.0;
    auto &neis = adj[u];
    for (auto &[v, val] : neis) {
      double res = dfs(v, t, vis);
      if (res > 0.0)
        return val * res;
    }
    return -1.0;
  }
};