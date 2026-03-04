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

class Solution {
public:
  vector<double> calcEquation(vector<vector<string>> &equations,
                              vector<double> &values,
                              vector<vector<string>> &queries) {
    unordered_map<string, int> umap;
    int n = 0;
    for (auto &e : equations) {
      auto &a = e[0], &b = e[1];
      if (!umap.count(a))
        umap[a] = n++;
      if (!umap.count(b))
        umap[b] = n++;
    }

    vector<vector<double>> dist(n, vector<double>(n, -1.0));
    for (int i = 0; i < n; ++i)
      dist[i][i] = 1.0;
    for (int i = 0; i < equations.size(); ++i) {
      int u = umap[equations[i][0]], v = umap[equations[i][1]];
      double val = values[i];
      dist[u][v] = val;
      dist[v][u] = 1.0 / val;
    }

    for (int k = 0; k < n; ++k)
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          if (dist[i][j] < 0 && dist[i][k] > 0 && dist[k][j] > 0)
            dist[i][j] = dist[i][k] * dist[k][j];

    vector<double> res;
    for (auto &q : queries) {
      auto &a = q[0], &b = q[1];
      if (!umap.count(a) || !umap.count(b)) {
        res.push_back(-1.0);
        continue;
      }
      res.push_back(dist[umap[a]][umap[b]]);
    }

    return res;
  }
};