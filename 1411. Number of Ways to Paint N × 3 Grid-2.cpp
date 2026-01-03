// mark
// 1845
// 輪廓線 DP
class Solution {
public:
  const int MOD = 1e9 + 7;
  // memo[row][col][color0][color1][color2]
  // 顏色用 0, 1, 2 表示，3 表示尚未著色（用於第一行初始狀態）
  int memo[5001][3][4][4][4];
  int n;
  int numOfWays(int n) {
    this->n = n;
    memset(memo, -1, sizeof(memo));

    return dfs(0, 0, 3, 3, 3);
  }

  long long dfs(int r, int c, int c0, int c1, int c2) {
    if (r == n)
      return 1;

    auto &res = memo[r][c][c0][c1][c2];
    if (res != -1)
      return res;

    int nr = (c == 2) ? r + 1 : r;
    int nc = (c == 2) ? 0 : c + 1;
    res = 0;
    for (int k = 0; k < 3; ++k) {
      bool ok = true;

      // 檢查左邊
      if (c == 0) {
        if (k == c0)
          ok = false; // 跟上方格子同色
      } else if (c == 1) {
        if (k == c1 || k == c0)
          ok = false; // 跟上方(c1)或左方(c0)同色
      } else if (c == 2) {
        if (k == c2 || k == c1)
          ok = false; // 跟上方(c2)或左方(c1)同色
      }

      if (ok) {
        // 更新輪廓線並往下一格走
        if (c == 0)
          res += dfs(nr, nc, k, c1, c2);
        else if (c == 1)
          res += dfs(nr, nc, c0, k, c2);
        else if (c == 2)
          res += dfs(nr, nc, c0, c1, k);
        res %= MOD;
      }
    }

    return res;
  }
};

class Solution {
public:
  int numOfWays(int n) {
    const int MOD = 1e9 + 7;

    long long dp[4][4][4];
    memset(dp, 0, sizeof(dp));
    dp[3][3][3] = 1;

    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < 3; ++c) {
        long long next_dp[4][4][4];
        memset(next_dp, 0, sizeof(next_dp));

        for (int c0 = 0; c0 <= 3; ++c0) {
          for (int c1 = 0; c1 <= 3; ++c1) {
            for (int c2 = 0; c2 <= 3; ++c2) {
              if (dp[c0][c1][c2] == 0)
                continue;

              for (int k = 0; k < 3; ++k) {
                bool ok = true;
                if (c == 0) {
                  if (k == c0)
                    ok = false; // 檢查上方
                } else if (c == 1) {
                  if (k == c1 || k == c0)
                    ok = false; // 檢查上方(c1)與左方(c0)
                } else if (c == 2) {
                  if (k == c2 || k == c1)
                    ok = false; // 檢查上方(c2)與左方(c1)
                }

                if (ok) {
                  // 根據當前填的 col (c)，更新對應的輪廓線位置
                  int nc0 = (c == 0) ? k : c0;
                  int nc1 = (c == 1) ? k : c1;
                  int nc2 = (c == 2) ? k : c2;

                  next_dp[nc0][nc1][nc2] =
                      (next_dp[nc0][nc1][nc2] + dp[c0][c1][c2]) % MOD;
                }
              }
            }
          }
        }
        memcpy(dp, next_dp, sizeof(dp));
      }
    }

    // 最後將所有合法狀態的數量加總
    long long res = 0;
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
        for (int k = 0; k < 3; ++k)
          res = (res + dp[i][j][k]) % MOD;

    return res;
  }
};