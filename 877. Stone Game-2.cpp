class Solution {
public:
  bool stoneGame(vector<int> &piles) {
    int n = piles.size();

    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i)
      prefix[i] = prefix[i - 1] + piles[i - 1];

    vector<vector<int>> dp(n, vector<int>(n, 0)); // score

    for (int i = 0; i < n; ++i)
      dp[i][i] = piles[i];

    for (int len = 2; len <= n; ++len) {
      for (int i = 0; i + len - 1 < n; ++i) {
        int j = i + len - 1;
        dp[i][j] =
            max(piles[i] + (prefix[j + 1] - prefix[i + 1]) - dp[i + 1][j],
                piles[j] + (prefix[j] - prefix[i]) - dp[i][j - 1]);
      }
    }

    return dp[0][n - 1] > (prefix[n] - dp[0][n - 1]);
  }
};