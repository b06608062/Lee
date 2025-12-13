// mark
// 數位 DP
// 表示在處理到第 i 位（從左到右）時，前 i 位中已經填入了 cnt1 個數字 1，
// 在此前提下，所有可以構造出的合法數字，其「整體出現 1 的總次數」之和。
class Solution {
public:
  string s;
  int dp[10][2][2][10];
  int countDigitOne(int n) {
    s = to_string(n);
    memset(dp, -1, sizeof(dp));

    return dfs(0, 0, 0, 0);
  }

  int dfs(int i, int free, int fix, int cnt1) {
    if (i == s.size())
      return cnt1;

    int &res = dp[i][free][fix][cnt1];
    if (res != -1)
      return res;

    res = 0;
    int up = free ? 9 : (s[i] - '0');

    if (fix == 0)
      res += dfs(i + 1, 1, 0, 0);

    for (int d = (fix == 0 ? 1 : 0); d <= up; ++d)
      res += dfs(i + 1, free || (d < up), 1, d == 1 ? cnt1 + 1 : cnt1);

    return res;
  }
};