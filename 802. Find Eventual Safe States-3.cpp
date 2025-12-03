class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<vector<int>> rg(n); // reverse graph
    vector<int> outdeg(n, 0);
    for (int u = 0; u < n; ++u) {
      outdeg[u] = graph[u].size();
      for (auto v : graph[u])
        rg[v].push_back(u); //  v -> u
    }

    queue<int> q;
    vector<bool> safe(n, false);
    for (int i = 0; i < n; ++i)
      if (outdeg[i] == 0) {
        q.push(i);
        safe[i] = true;
      }

    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (auto u : rg[v]) {
        if (--outdeg[u] == 0) {
          safe[u] = true;
          q.push(u);
        }
      }
    }

    vector<int> res;
    for (int i = 0; i < n; ++i)
      if (safe[i])
        res.push_back(i);
    return res;
  }
};
