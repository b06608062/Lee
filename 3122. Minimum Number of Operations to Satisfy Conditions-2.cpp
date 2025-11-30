struct Cand {
  int val, cnt;
};

class Solution {
public:
  int minimumOperations(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    const int INF = m * n;

    vector<vector<Cand>> cand(n);
    for (int col = 0; col < n; ++col) {
      int cnt[10] = {0};
      for (int row = 0; row < m; ++row)
        cnt[grid[row][col]]++;
      vector<int> idx(10);
      iota(idx.begin(), idx.end(), 0); // 0..9
      sort(idx.begin(), idx.end(),
           [&](int a, int b) { return cnt[a] > cnt[b]; });
      for (int p = 0; p < 3; ++p) {
        int d = idx[p];
        cand[col].push_back({d, cnt[d]});
      }
    }

    vector<vector<int>> dp(n, vector<int>(3, INF));

    for (int p = 0; p < 3; ++p)
      dp[0][p] = m - cand[0][p].cnt;

    for (int col = 1; col < n; ++col) {
      for (int p = 0; p < 3; ++p) {
        int v = cand[col][p].val;
        int cost = m - cand[col][p].cnt;
        for (int q = 0; q < 3; ++q) {
          if (cand[col - 1][q].val == v)
            continue;
          dp[col][p] = min(dp[col][p], dp[col - 1][q] + cost);
        }
      }
    }

    int res = INF;
    for (int p = 0; p < 3; ++p)
      res = min(res, dp[n - 1][p]);

    return res;
  }
};
