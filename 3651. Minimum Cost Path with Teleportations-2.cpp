// mark
// 2411

struct Node {
  int value;
  int cost;
  int r;
  int c;
};

class Solution {
public:
  const int INF = INT_MAX / 2;
  int minCost(vector<vector<int>> &grid, int k) {
    int n = grid.size(), m = grid[0].size();

    vector<vector<vector<int>>> dp(k + 1,
                                   vector<vector<int>>(n, vector<int>(m, INF)));

    dp[0][0][0] = 0;
    for (int step = 0; step <= k; ++step) {
      if (step > 0) {
        vector<Node> cells;
        for (int r = 0; r < n; ++r)
          for (int c = 0; c < m; ++c)
            cells.push_back({grid[r][c], dp[step - 1][r][c], r, c});

        sort(cells.begin(), cells.end(), [](auto &a, auto &b) {
          if (a.value != b.value)
            return a.value > b.value;
          return a.cost < b.cost;
        });

        int best = INF;
        for (auto &node : cells) {
          best = min(best, node.cost);
          dp[step][node.r][node.c] = best;
        }
      }

      for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
          int res = dp[step][r][c];
          if (r > 0)
            res = min(res, dp[step][r - 1][c] + grid[r][c]);
          if (c > 0)
            res = min(res, dp[step][r][c - 1] + grid[r][c]);
          dp[step][r][c] = res;
        }
      }
    }

    return dp[k][n - 1][m - 1];
  }
};
