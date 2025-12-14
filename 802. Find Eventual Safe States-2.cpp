class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int n = graph.size();

    vector<vector<int>> revG(n);
    vector<int> outdeg(n, 0);
    for (int u = 0; u < n; ++u)
      for (auto v : graph[u]) {
        revG[v].push_back(u);
        outdeg[u]++;
      }

    queue<int> q;
    for (int i = 0; i < n; ++i)
      if (outdeg[i] == 0)
        q.push(i);

    vector<int> res;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      res.push_back(u);
      for (auto v : revG[u])
        if (--outdeg[v] == 0)
          q.push(v);
    }

    sort(res.begin(), res.end());

    return res;
  }
};