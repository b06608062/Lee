class Solution {
public:
  vector<vector<int>> adj;
  int k, res;
  int maxKDivisibleComponents(int n, vector<vector<int>> &edges,
                              vector<int> &values, int k) {
    adj = vector<vector<int>>(n);
    for (auto e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    this->k = k;
    res = 0;
    dfs(values, 0, -1);

    return res;
  }

  long long dfs(vector<int> &values, int u, int parent) {
    long long sum = values[u];
    for (auto v : adj[u]) {
      if (v != parent) {
        sum += dfs(values, v, u);
      }
    }

    if (sum % k == 0) {
      res++;
      return 0;
    }
    return sum;
  }
};