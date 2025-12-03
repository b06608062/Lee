class Solution {
public:
  vector<int> color;
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int n = graph.size();
    color.assign(n, 0);
    vector<int> res;

    for (int i = 0; i < n; ++i)
      if (dfs(graph, i))
        res.push_back(i);

    return res;
  }
  bool dfs(vector<vector<int>> &graph, int u) {
    if (color[u] != 0)
      return color[u] == 2;
    color[u] = 1;
    for (int v : graph[u])
      if (!dfs(graph, v))
        return false;
    color[u] = 2;
    return true;
  }
};
