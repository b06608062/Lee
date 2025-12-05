// mark
// 2042
// Pipeline DP
// 正向 DP + 反向修正
class Solution {
public:
  long long minTime(vector<int> &skill, vector<int> &mana) {
    int n = skill.size();
    vector<long long> f(n, 0);

    for (auto x : mana) {
      f[0] += skill[0] * x;
      for (int i = 1; i < n; ++i)
        f[i] = max(f[i], f[i - 1]) + skill[i] * x;
      for (int i = n - 2; i >= 0; --i)
        f[i] = f[i + 1] - skill[i + 1] * x;
    }

    return f[n - 1];
  }
};

// 改成不需要連續
class Solution {
public:
  long long minTime(vector<int> &skill, vector<int> &mana) {
    int n = skill.size(), m = mana.size();

    vector<vector<long long>> dp(n, vector<long long>(m, 0));

    dp[0][0] = 1LL * skill[0] * mana[0];
    for (int j = 1; j < m; ++j)
      dp[0][j] = dp[0][j - 1] + 1LL * skill[0] * mana[j];

    for (int i = 1; i < n; ++i)
      dp[i][0] = dp[i - 1][0] + 1LL * skill[i] * mana[0];

    for (int j = 1; j < m; ++j)
      for (int i = 1; i < n; ++i)
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 1LL * skill[i] * mana[j];

    return dp[n - 1][m - 1];
  }
};
