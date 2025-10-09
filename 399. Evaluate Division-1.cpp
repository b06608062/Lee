class Solution {
public:
  unordered_map<string, unordered_map<string, double>> adj;
  vector<double> calcEquation(vector<vector<string>> &equations,
                              vector<double> &values,
                              vector<vector<string>> &queries) {
    for (int i = 0; i < equations.size(); ++i) {
      string &A = equations[i][0], &B = equations[i][1];
      double val = values[i];
      adj[A][B] = val;
      adj[B][A] = 1 / val;
    }

    vector<double> res;
    for (auto &q : queries) {
      string &A = q[0], &B = q[1];
      if (!adj.count(A) || !adj.count(B)) {
        res.push_back(-1.0);
        continue;
      }
      unordered_set<string> vis;
      res.push_back(dfs(A, B, vis));
    }

    return res;
  }

  double dfs(const string &A, const string &B, unordered_set<string> &vis) {
    if (vis.count(A))
      return -1.0;

    vis.insert(A);
    if (A == B)
      return 1.0;

    for (auto &[C, val] : adj[A]) {
      double d = dfs(C, B, vis);
      if (d > 0.0)
        return val * d;
    }

    return -1.0;
  }
};