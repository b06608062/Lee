class Solution {
public:
  int maxPathScore(vector<vector<int>> &grid, int k) {
    const int inf = INT_MIN / 2;
    int m = grid.size(), n = grid[0].size();

    vector memo(m, vector(n, vector<int>(k + 1, -1))); // 至多
    for (int i = 0; i <= k; ++i)
      memo[0][0][i] = 0;

    auto dfs = [&](this auto &&dfs, int i, int j, int k) {
      if (i < 0 || j < 0 || k < 0)
        return inf;
      if (memo[i][j][k] != -1)
        return memo[i][j][k];
      int x = grid[i][j];
      int nxtK = k - (x > 0 ? 1 : 0);
      return memo[i][j][k] = max(dfs(i - 1, j, nxtK), dfs(i, j - 1, nxtK)) + x;
    };

    int res = dfs(m - 1, n - 1, k);

    return res < 0 ? -1 : res;
  }
};