class Solution {
public:
  vector<double> calcEquation(vector<vector<string>> &equations,
                              vector<double> &values,
                              vector<vector<string>> &queries) {
    unordered_map<string, unordered_map<string, double>> adj;
    unordered_set<string> uset;
    for (int i = 0; i < equations.size(); ++i) {
      string &u = equations[i][0], &v = equations[i][1];
      double val = values[i];
      adj[u][v] = val;
      adj[v][u] = 1 / val;
      uset.insert(u);
      uset.insert(v);
    }

    for (auto &v : uset)
      adj[v][v] = 1.0;

    for (auto &k : uset)
      for (auto &u : uset)
        for (auto &v : uset)
          if (adj[u].count(k) && adj[k].count(v))
            adj[u][v] = adj[u][k] * adj[k][v];

    vector<double> res;
    for (auto &q : queries) {
      string &u = q[0], &v = q[1];
      if (!uset.count(u) || !uset.count(v)) {
        res.push_back(-1.0);
        continue;
      }
      if (adj[u].count(v))
        res.push_back(adj[u][v]);
      else
        res.push_back(-1.0);
    }

    return res;
  }
};