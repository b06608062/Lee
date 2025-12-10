// TODO
// 2419
// 數位 DP
class Solution {
public:
  string s;
  vector<vector<vector<long long>>> memo;
  long long countNoZeroPairs(long long n) {
    s = to_string(n);
    int m = s.size();
    memo = vector<vector<vector<long long>>>(
        m, vector<vector<long long>>(2, vector<long long>(2, -1)));

    return dfs(m - 1, false, true);
  }

  long long dfs(int i, bool borrowed, bool isNum) {
    if (i < 0)
      return !borrowed;

    long long res = memo[i][borrowed][isNum];
    if (res != -1)
      return res;

    int d = s[i] - '0' - borrowed;

    res = 0;
    // 兩數都不為 0
    if (isNum) {
      res += dfs(i - 1, false, true) * calc(d);     // 不向高位借 1
      res += dfs(i - 1, true, true) * calc(d + 10); // 向高位借 1
    }

    // 其中一個數位填前導 0
    if (i < s.size() - 1) { // 不能是最低位，否則有一數為 0
      if (d != 0)           // d 不能是 0
        // 如果 d < 0，必须向高位借 1
        // 如果 isNum = true，根據對稱性 a or b 為前導 0，要乘以 2
        res += dfs(i - 1, d < 0, false) * (isNum + 1);
      else if (i == 0) // d = 0
        res++;         // 只有當最高位，兩數才能都填
    }

    return memo[i][borrowed][isNum] = res;
  }

  int calc(int target) {
    if (target < 2)
      return 0;
    return target < 10 ? target - 1 : 19 - target;
  }
};