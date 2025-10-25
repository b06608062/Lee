class Solution {
public:
  int countCoprime(vector<vector<int>> &mat) {
    constexpr int MOD = 1'000'000'007;
    const int V = 150;

    vector<int> dp(V + 1, 0), temp(V + 1, 0);
    dp[0] = 1;

    for (auto &row : mat) {
      fill(temp.begin(), temp.end(), 0);
      for (auto x : row)
        for (int i = 0; i <= 150; ++i) {
          int nexG = gcd(x, i);
          temp[nexG] += dp[i];
          if (temp[nexG] >= MOD)
            temp[nexG] -= MOD;
        }

      swap(dp, temp);
    }

    return dp[1];
  }
};