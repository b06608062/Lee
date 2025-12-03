class Solution {
public:
  unordered_set<int> safe;
  vector<bool> vis;
  int n;
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    n = graph.size();
    vis.assign(n, false);

    for (int i = 0; i < n; ++i)
      dfs(graph, i);

    vector<int> res(safe.begin(), safe.end());
    sort(res.begin(), res.end());

    return res;
  }

  bool dfs(vector<vector<int>> &graph, int i) {
    if (vis[i])
      return safe.find(i) != safe.end();
    vis[i] = true;
    bool vaild = true;
    for (auto j : graph[i])
      vaild &= dfs(graph, j);
    if (vaild)
      safe.insert(i);
    return vaild;
  }
};