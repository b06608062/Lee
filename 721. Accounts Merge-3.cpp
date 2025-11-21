class Solution {
public:
  vector<vector<int>> adj;
  vector<int> vis;
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    int n = accounts.size();

    adj = vector<vector<int>>(n);
    vis = vector<int>(n, 0);

    for (int i = 0; i < n; ++i) {
      auto &acc1 = accounts[i];
      unordered_set<string> uset(acc1.begin() + 1, acc1.end());
      for (int j = i + 1; j < n; ++j) {
        auto &acc2 = accounts[j];
        if (acc1[0] != acc2[0])
          continue;
        for (int k = 1; k < acc2.size(); ++k)
          if (uset.count(acc2[k])) {
            adj[i].push_back(j);
            adj[j].push_back(i);
            break;
          }
      }
    }

    vector<vector<string>> res;
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        res.push_back({});
        set<string> emails;
        dfs(accounts, emails, i);
        res.back().push_back(accounts[i][0]);
        for (auto &mail : emails)
          res.back().push_back(mail);
      }
    }

    return res;
  }

  void dfs(vector<vector<string>> &accounts, set<string> &emails, int u) {
    if (vis[u])
      return;

    vis[u] = 1;
    auto &acc = accounts[u];
    for (int i = 1; i < acc.size(); ++i)
      emails.insert(acc[i]);

    for (auto v : adj[u])
      dfs(accounts, emails, v);
  }
};