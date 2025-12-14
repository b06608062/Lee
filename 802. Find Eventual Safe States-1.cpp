class Solution {
public:
  vector<int> colors; // 0, 1, 2
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int n = graph.size();

    colors.assign(n, 0);
    for (int i = 0; i < n; ++i)
      dfs(graph, i);

    vector<int> res;
    for (int i = 0; i < n; ++i)
      if (colors[i] == 2)
        res.push_back(i);

    return res;
  }

  bool dfs(vector<vector<int>> &graph, int u) {
    if (colors[u] != 0)
      return colors[u] == 2;
    colors[u] = 1;
    for (auto v : graph[u])
      if (!dfs(graph, v))
        return false;
    colors[u] = 2;
    return true;
  }
};