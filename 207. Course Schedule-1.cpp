class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
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

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto v : adj[u])
        if (--indeg[v] == 0)
          q.push(v);
    }

    for (int i = 0; i < numCourses; ++i)
      if (indeg[i])
        return false;

    return true;
  }
};