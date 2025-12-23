// mark
// 2247
// 字符版串特殊 LIS
class Solution {
public:
  int n, m;
  int minDeletionSize(vector<string> &strs) {
    n = strs.size(), m = strs[0].size();

    vector<int> dp(m, 1);
    for (int j = 1; j < m; ++j)
      for (int k = 0; k < j; ++k)
        if (valid(strs, j, k))
          dp[j] = max(dp[j], dp[k] + 1);

    return m - *max_element(dp.begin(), dp.end());
  }

  bool valid(vector<string> &strs, int j, int k) {
    for (int i = 0; i < n; ++i)
      if (strs[i][j] < strs[i][k])
        return false;
    return true;
  }
};