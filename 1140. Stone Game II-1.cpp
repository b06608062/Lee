class Solution {
public:
  int stoneGameII(vector<int> &piles) {
    int n = piles.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = n - 1; i >= 0; --i) {
      int suffix = accumulate(piles.begin() + i, piles.end(), 0);
      for (int M = 1; M <= n; ++M) {
        if (i + 2 * M - 1 >= n - 1) {
          dp[i][M] = suffix;
          continue;
        }

        int sum = 0, best = INT_MIN / 2;
        for (int X = 1; X <= 2 * M; ++X) {
          sum += piles[i + X - 1];
          best = max(best, sum - dp[i + X][max(M, X)]);
        }
        dp[i][M] = best;
      }
    }

    // A - B = dp[0][1]
    // A + B = total
    // 2A = total + dp[0][1]
    // A = (total + dp[0][1]) / 2
    int total = accumulate(piles.begin(), piles.end(), 0);
    return (total + dp[0][1]) / 2;
  }
};

class Solution {
public:
  int stoneGameII(vector<int> &piles) {
    int n = piles.size();
    const int INF = INT_MAX / 2;
    vector<vector<int>> f(n + 1, vector<int>(n + 1, -INF));
    vector<int> suff(n + 1, 0);
    for (int M = 0; M <= n; ++M)
      f[n][M] = 0;
    for (int i = n - 1; i >= 0; --i)
      suff[i] = suff[i + 1] + piles[i];

    for (int i = n - 1; i >= 0; --i) {
      for (int M = 1; M <= n; ++M) {
        if (i + 2 * M - 1 >= n - 1) {
          f[i][M] = suff[i];
          continue;
        }
        int sum = 0;
        for (int X = 1; X <= 2 * M; ++X) {
          sum += piles[i + X - 1];
          f[i][M] = max(f[i][M], sum - f[i + X][max(M, X)]);
        }
      }
    }
    // A - B = f[0][1]
    // A + B = suff[0]
    // A = (f[0][1] + suff[0]) / 2
    return (f[0][1] + suff[0]) / 2;
  }
};