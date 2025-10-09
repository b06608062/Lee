class Solution {
public:
  int n;
  vector<vector<int>> memo;
  int stoneGameII(vector<int> &piles) {
    n = piles.size();

    memo = vector<vector<int>>(n + 1, vector<int>(n + 1, INT_MIN / 2));

    for (int M = 0; M <= n; ++M)
      memo[n][M] = 0;

    int total = accumulate(piles.begin(), piles.end(), 0);
    return (total + helper(piles, 0, 1)) / 2;
  }

  int helper(vector<int> &piles, int i, int M) {
    if (memo[i][M] != INT_MIN / 2)
      return memo[i][M];

    if (i + 2 * M - 1 >= n - 1)
      return memo[i][M] = accumulate(piles.begin() + i, piles.end(), 0);

    int sum = 0, best = INT_MIN;
    for (int X = 1; X <= 2 * M; ++X) {
      sum += piles[i + X - 1];
      best = max(best, sum - helper(piles, i + X, max(M, X)));
    }

    return memo[i][M] = best;
  }
};