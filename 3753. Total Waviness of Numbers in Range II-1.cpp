// mark
// 2297
// 數位 DP 進階困難
class Solution {
public:
  long long totalWaviness(long long num1, long long num2) {
    string s1 = to_string(num1 - 1);
    string s2 = to_string(num2);
    // i, free, fix, comp, dig, cntw
    // i : 當前處理到第幾個位數
    // free : 可以開始亂填不受 s[i] 限制
    // fix : 前面填了多少數，最少 2 個即可開始計算 waviness，後面就一直保持 2
    // 即可 comp : "上上個數" 跟 "上個數" 數的大小關係，1 上升, 0 平等, -1 下降
    // dig : "上個數" 填哪個值，0 ~ 9
    // cntw : 當前累計多少個合法的 waviness，最多位數 - 2 個，0 ~ 14
    long long dp1[16][2][3][3][10][15];
    long long dp2[16][2][3][3][10][15];
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    return dfs(dp2, s2, 0, 0, 0, 0, 0, 0) - dfs(dp1, s1, 0, 0, 0, 0, 0, 0);
  }

  long long dfs(long long dp[][2][3][3][10][14], string &s, int i, int free,
                int fix, int comp, int dig, int cntw) {
    if (i == s.size())
      return cntw;

    long long &res = dp[i][free][fix][comp + 1][dig][cntw];
    if (res != -1)
      return res;

    res = 0;
    int up = free ? 9 : (s[i] - '0');
    if (fix == 0)
      res += dfs(dp, s, i + 1, 1, 0, 0, 0, 0);

    for (int d = (fix ? 0 : 1); d <= up; ++d) {
      if (fix > 0) {
        int nextComp = (d > dig) - (d < dig);
        int w = cntw;
        if (comp * nextComp < 0)
          w++;
        res += dfs(dp, s, i + 1, free || d < up, 2, nextComp, d, w);
      } else {
        res += dfs(dp, s, i + 1, free || d < up, 1, 0, d, 0);
      }
    }

    return res;
  }
};