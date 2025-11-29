class Solution {
public:
  string stoneGameIII(vector<int> &stoneValue) {
    int n = stoneValue.size();
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
      int cur = 0, best = INT_MIN;
      for (int j = 0; j < 3 && i + j < n; ++j) {
        cur += stoneValue[i + j];
        best = max(best, cur - dp[i + j + 1]);
      }
      dp[i] = best;
    }

    return dp[0] == 0 ? "Tie" : dp[0] < 0 ? "Bob" : "Alice";
  }
};