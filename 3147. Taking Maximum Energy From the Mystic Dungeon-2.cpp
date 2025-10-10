class Solution {
public:
  int maximumEnergy(vector<int> &energy, int k) {
    int n = energy.size();

    vector<int> dp(n, INT_MIN);

    int res = INT_MIN / 2;
    for (int i = n - 1; i >= 0; --i) {
      dp[i] = energy[i] + (i + k < n ? dp[i + k] : 0);
      res = max(res, dp[i]);
    }

    return res;
  }
};