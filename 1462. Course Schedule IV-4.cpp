class Solution {
public:
  vector<bool> checkIfPrerequisite(int numCourses,
                                   vector<vector<int>> &prerequisites,
                                   vector<vector<int>> &queries) {
    int n = numCourses;
    vector<vector<int>> adj(n);
    for (auto &p : prerequisites)
      adj[p[0]].push_back(p[1]);

    vector<vector<bool>> f(n, vector<bool>(n, false));

    for (int i = 0; i < n; ++i) {
      queue<int> q;
      q.push(i);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
          if (!f[i][v]) {
            f[i][v] = true;
            q.push(v);
          }
        }
      }
    }

    int m = queries.size();
    vector<bool> res;
    for (int i = 0; i < m; ++i)
      res.push_back(f[queries[i][0]][queries[i][1]]);
    return res;
  }
};