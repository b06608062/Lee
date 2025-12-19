// mark
// 2004
// 按時間分層處理的傳播問題 + Graph 子圖 + DFS
class Solution {
public:
  vector<bool> shared;
  vector<int> findAllPeople(int n, vector<vector<int>> &meetings,
                            int firstPerson) {
    int m = meetings.size();
    sort(meetings.begin(), meetings.end(),
         [](auto &a, auto &b) { return a[2] < b[2]; });

    shared.assign(n, false);
    shared[0] = shared[firstPerson] = true;

    int i = 0, cur = 0;
    while (i < m) {
      cur = max(cur, meetings[i][2]);

      unordered_map<int, vector<int>> adj;
      while (i < m && meetings[i][2] == cur) {
        int x = meetings[i][0], y = meetings[i][1];
        adj[x].push_back(y);
        adj[y].push_back(x);
        i++;
      }

      unordered_map<int, bool> vis;
      for (auto &[x, _] : adj)
        if (shared[x])
          dfs(adj, vis, x);
    }

    vector<int> res;
    for (i = 0; i < n; ++i)
      if (shared[i])
        res.push_back(i);

    return res;
  }

  void dfs(unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &vis,
           int u) {
    if (vis[u])
      return;
    vis[u] = true;
    shared[u] = true;
    for (auto v : adj[u])
      dfs(adj, vis, v);
  }
};