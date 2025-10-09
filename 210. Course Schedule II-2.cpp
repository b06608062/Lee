class Solution {
public:
  vector<int> res;
  vector<vector<int>> adj;
  vector<int> state;
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    adj = vector<vector<int>>(numCourses);
    state = vector<int>(numCourses, 0); // 0: white, 1: gray, 2: black

    for (auto &p : prerequisites) {
      int u = p[1], v = p[0];
      adj[u].push_back(v);
    }

    for (int i = 0; i < numCourses; ++i)
      if (!dfs(i))
        return {};

    reverse(res.begin(), res.end());

    return res;
  }

  bool dfs(int u) {
    if (state[u] == 1)
      return false;
    if (state[u] == 2)
      return true;

    state[u] = 1;
    for (auto v : adj[u])
      if (!dfs(v))
        return false;
    state[u] = 2;

    res.push_back(u);

    return true;
  };
};
