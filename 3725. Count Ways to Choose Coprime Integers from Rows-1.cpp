// mark
// 1982
// DP + GCD 狀態壓縮 + 空間優化
// O (m * n * U * log U)
class Solution {
public:
  int countCoprime(vector<vector<int>> &mat) {
    const int MOD = 1e9 + 7;
    int m = mat.size();

    vector<int> dp(151, 0), temp(151, 0);

    dp[0] = 1;
    for (int i = 0; i < m; ++i) {
      fill(temp.begin(), temp.end(), 0);
      auto &row = mat[i];
      for (auto x : row)
        for (int g = 0; g <= 150; ++g) {
          int nxtG = gcd(g, x);
          temp[nxtG] += dp[g];
          if (temp[nxtG] >= MOD)
            temp[nxtG] -= MOD;
        }
      swap(dp, temp);
    }

    return dp[1];
  }
};