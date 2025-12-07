// mark
// 1712
// 著色問題 + Greedy
class Solution {
public:
  vector<int> colors;
  vector<vector<int>> adj;
  vector<int> gardenNoAdj(int n, vector<vector<int>> &paths) {
    colors.assign(n + 1, 0);
    adj.resize(n + 1);

    for (auto &path : paths) {
      int u = path[0], v = path[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
      dfs(i);

    vector<int> res(colors.begin() + 1, colors.end());
    return res;
  }

  void dfs(int u) {
    if (colors[u])
      return;

    int used[5] = {0, 0, 0, 0, 0};
    for (auto v : adj[u])
      used[colors[v]]++;
    for (int i = 1; i <= 4; ++i)
      if (!used[i]) {
        colors[u] = i;
        break;
      }

    for (auto v : adj[u])
      dfs(v);
  }
};