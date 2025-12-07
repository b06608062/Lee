// mark
// 1985
// 區間合併 + 組合計數
// dp[0] = 1
// DP：dp[i] = dp[0] + ... + dp[i-1] ⇒ dp[i] = 2^(i-1)
class Solution {
public:
  int numberOfGoodPartitions(vector<int> &nums) {
    const int MOD = 1e9 + 7;
    int n = nums.size();

    unordered_map<int, int> right;
    for (int i = 0; i < n; ++i)
      right[nums[i]] = i;

    int r = 0, cur = 0, cnt = 1;
    while (r < n) {
      if (r > cur)
        cnt++;
      cur = max(cur, right[nums[r]]);
      r++;
    }

    // dp[i] = dp[i−1] + dp[i−2] + ⋯ + dp[0]
    // or 2 ^ (cnt - 1)
    int res = 1;
    while (--cnt) {
      res <<= 1;
      if (res >= MOD)
        res %= MOD;
    }

    return res;
  }
};