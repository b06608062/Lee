class Solution {
public:
  vector<vector<int>> adj;
  string s;
  int res = 1;
  int longestPath(vector<int> &parent, string s) {
    int n = s.size();

    adj.resize(n);
    this->s = s;

    for (int i = 1; i < n; ++i)
      if (parent[i] != -1)
        adj[parent[i]].push_back(i);

    dfs(0);

    return res;
  }

  int dfs(int i) {
    if (adj[i].size() == 0)
      return 1;
    char ch = s[i];
    int max_x = 0;
    for (auto j : adj[i]) {
      int max_y = dfs(j);
      if (s[j] != ch) {
        res = max(res, max_x + max_y + 1);
        max_x = max(max_x, max_y);
      }
    }

    return max_x + 1;
  }
};