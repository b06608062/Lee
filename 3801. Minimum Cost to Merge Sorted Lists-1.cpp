// mark
// 2399
// 子集狀態壓縮 DP +  預處理
class Solution {
public:
  long long minMergeCost(vector<vector<int>> &lists) {
    int n = lists.size();
    int u = 1 << n;
    vector<vector<int>> dp(u);
    for (int i = 0; i < n; ++i) {
      int high = 1 << i;
      for (int s = 0; s < high; ++s)
        dp[s | high] = merge(dp[s], lists[i]);
    }

    vector<long long> f(u);
    for (int i = 3; i < u; ++i) {
      if ((i & (i - 1)) == 0)
        continue;
      f[i] = LLONG_MAX;
      for (int j = (i - 1) & i; j > (i ^ j); j = (j - 1) & i) {
        int k = i ^ j;
        int lj = dp[j].size(), lk = dp[k].size();
        int mj = dp[j][(lj - 1) / 2], mk = dp[k][(lk - 1) / 2];
        f[i] = min(f[i], f[j] + f[k] + lj + lk + abs(mj - mk));
      }
    }

    return f[u - 1];
  }

  vector<int> merge(vector<int> &a, vector<int> &b) {
    int n = a.size(), m = b.size();
    vector<int> c(n + m);
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
      if (a[i] <= b[j])
        c[k++] = a[i++];
      else
        c[k++] = b[j++];
    while (i < n)
      c[k++] = a[i++];
    while (j < m)
      c[k++] = b[j++];
    return c;
  }
};