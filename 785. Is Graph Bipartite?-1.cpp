class Solution {
public:
  bool isBipartite(vector<vector<int>> &graph) {
    int n = graph.size();

    vector<int> colors(n, 0);

    auto dfs = [&](this auto &&dfs, int u, int c) -> bool {
      colors[u] = c;
      for (auto v : graph[u])
        if (colors[v] == c || colors[v] == 0 && !dfs(v, -c))
          return false;
      return true;
    };

    for (int i = 0; i < n; ++i)
      if (!colors[i] && !dfs(i, 1))
        return false;

    return true;
  }
};