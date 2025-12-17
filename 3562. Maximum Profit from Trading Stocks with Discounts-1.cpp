// mark
// 2458
// 樹形 0/1 背包
// 不需要 MEMO
class Solution {
public:
  vector<int> p, f;
  vector<vector<int>> adj;
  int n, budget;
  int maxProfit(int n, vector<int> &present, vector<int> &future,
                vector<vector<int>> &hierarchy, int budget) {
    p = present, f = future;
    this->n = n, this->budget = budget;
    adj.resize(n);
    for (auto &h : hierarchy) {
      int i = h[0] - 1, j = h[1] - 1;
      adj[i].push_back(j);
    }

    auto [dp0, _] = dfs(0);

    return dp0[budget];
  }

  pair<vector<int>, vector<int>> dfs(int i) {
    int cost = p[i];
    int hcost = cost / 2;

    vector<int> subP0(budget + 1, 0), subP1(budget + 1, 0);
    for (auto j : adj[i]) {
      auto [subDp0, subDp1] = dfs(j);
      for (int b = budget; b >= 0; --b)
        for (int sub = 0; sub <= b; ++sub) {
          subP0[b] = max(subP0[b], subP0[b - sub] + subDp0[sub]);
          subP1[b] = max(subP1[b], subP1[b - sub] + subDp1[sub]);
        }
    }

    vector<int> dp0 = subP0, dp1 = subP0;
    for (int b = 0; b <= budget; ++b) {
      if (b - cost >= 0)
        dp0[b] = max(dp0[b], subP1[b - cost] + f[i] - cost);
      if (b - hcost >= 0)
        dp1[b] = max(dp1[b], subP1[b - hcost] + f[i] - hcost);
    }

    return {dp0, dp1}; // 沒打折, 有打折
  }
};