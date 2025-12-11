// mark
// 1990
// 數位 DP 入門
class Solution {
public:
  string s;
  vector<int> digs;
  int dp[10][2][2];
  int atMostNGivenDigitSet(vector<string> &digits, int n) {
    s = to_string(n);
    for (auto &d : digits)
      digs.push_back(d[0] - '0');
    memset(dp, -1, sizeof(dp));

    return dfs(0, 0, 0);
  }

  int dfs(int i, int free, int fix) {
    if (i == s.size())
      return fix ? 1 : 0;

    int &res = dp[i][free][fix];
    if (res != -1)
      return res;

    res = 0;
    int up = free ? 9 : (s[i] - '0');

    if (fix == 0)
      res += dfs(i + 1, 1, 0);

    for (int d : digs) {
      if (d > up)
        break;
      res += dfs(i + 1, free || (d < up), 1);
    }

    return res;
  }
};