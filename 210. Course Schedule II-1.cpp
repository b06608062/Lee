class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> indeg(numCourses, 0);
    for (auto &p : prerequisites) {
      int u = p[1], v = p[0];
      adj[u].push_back(v);
      indeg[v]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; ++i)
      if (indeg[i] == 0)
        q.push(i);

    vector<int> res;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      res.push_back(u);
      for (auto v : adj[u])
        if (--indeg[v] == 0)
          q.push(v);
    }

    if (res.size() < numCourses)
      return {};

    return res;
  }
};