class Solution {
public:
  string s;
  vector<vector<vector<long long>>> dp; // dp[i][borrowed][isNum]
  long long countNoZeroPairs(long long n) {
    s = to_string(n);
    int m = s.size();
    dp = vector<vector<vector<long long>>>(
        m, vector<vector<long long>>(2, vector<long long>(2, -1)));

    for (int i = 0; i < m; ++i)
      for (int borrowed = 0; borrowed <= 1; ++borrowed)
        for (int isNum = 0; isNum <= 1; ++isNum) {
          int d = (s[i] - '0') - borrowed;

          long long res = 0;
          // 兩數都不為 0
          if (isNum)
            if (i - 1 >= 0) {
              res += dp[i - 1][0][1] * calc(d);      // 不向高位借 1
              res += dp[i - 1][1][1] * calc(d + 10); // 向高位借 1
            } else {
              res += (1LL) * calc(d);      // 不向高位借 1
              res += (0LL) * calc(d + 10); // 向高位借 1
            }

          // 其中一個數位填前導 0
          if (i < m - 1)
            if (d != 0)
              if (i - 1 >= 0)
                res += dp[i - 1][(d < 0)][0] * (isNum + 1);
              else // i = 0
                res += ((d < 0) ? 0LL : 1LL) * (isNum + 1);
            else if (i == 0) // d = 0
              res += 1;

          dp[i][borrowed][isNum] = res;
        }

    return dp[m - 1][0][1];
  }

  int calc(int target) {
    if (target < 2)
      return 0;
    return target < 10 ? target - 1 : 19 - target;
  }
};
