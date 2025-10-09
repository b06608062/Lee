class Solution {
public:
  vector<bool> checkIfPrerequisite(int numCourses,
                                   vector<vector<int>> &prerequisites,
                                   vector<vector<int>> &queries) {
    vector<vector<int>> adj(numCourses);
    vector<int> indeg(numCourses, 0);
    for (auto &p : prerequisites) {
      int u = p[0], v = p[1];
      adj[u].push_back(v);
      indeg[v]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; ++i)
      if (indeg[i] == 0)
        q.push(i);

    constexpr int MAXN = 100;
    vector<bitset<MAXN>> limit(numCourses);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : adj[u]) {
        limit[v].set(u);
        limit[v] |= limit[u];
        if (--indeg[v] == 0)
          q.push(v);
      }
    }

    vector<bool> res;
    for (auto &q : queries)
      res.push_back(limit[q[1]].test(q[0]));

    return res;
  }
};
