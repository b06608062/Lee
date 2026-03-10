class Solution {
public:
  vector<vector<int>> memo;
  const int INF = INT_MAX / 2;
  bool stoneGame(vector<int> &piles) {
    int n = piles.size();
    memo.assign(n, vector<int>(n, -INF));
    return dfs(piles, 0, n - 1) > 0;
  }

  int dfs(vector<int> &piles, int i, int j) {
    if (i == j)
      return piles[i];
    int &res = memo[i][j];
    if (res != -INF)
      return res;
    return res = max(piles[i] - dfs(piles, i + 1, j),
                     piles[j] - dfs(piles, i, j - 1));
  }
};