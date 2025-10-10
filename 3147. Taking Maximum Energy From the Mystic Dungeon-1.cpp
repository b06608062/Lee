class Solution {
public:
  int maximumEnergy(vector<int> &energy, int k) {
    int n = energy.size();

    vector<int> dp(n, INT_MIN);

    for (int i = 0; i < n; ++i)
      if (i < k)
        dp[i] = energy[i];
      else
        dp[i] = max(dp[i - k] + energy[i], energy[i]);

    return *max_element(dp.end() - k, dp.end());
  }
};