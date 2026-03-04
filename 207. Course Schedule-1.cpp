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

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    // b -> a
    int n = numCourses;
    vector<vector<int>> adj(n);
    vector<int> ind(n, 0);
    for (auto &p : prerequisites) {
      int a = p[0], b = p[1];
      adj[b].push_back(a);
      ind[a]++;
    }

    int cnt = 0;
    queue<int> q;
    for (int i = 0; i < n; ++i)
      if (ind[i] == 0) {
        cnt++;
        q.push(i);
      }

    while (!q.empty() && cnt < n) {
      auto u = q.front();
      q.pop();
      for (auto v : adj[u]) {
        if (--ind[v] == 0) {
          cnt++;
          q.push(v);
        }
      }
    }
    return cnt == n;
  }
};
