class Solution {
public:
  int countDigitOne(int n) {
    string s = to_string(n);
    int m = s.size();
    vector memo(m, vector<int>(m, -1));
    // 定義 dfs(i, cnt1, isLimit)：
    // 表示在處理到第 i 位（從左到右）時，前 i 位中已經填入了 cnt1 個數字 1，
    // 在此前提下，所有可以構造出的合法數字，其「整體出現 1 的總次數」之和。
    auto dfs = [&](this auto &&dfs, int i, int cnt1, bool is_limit) -> int {
      if (i == m)
        return cnt1;

      if (!is_limit && memo[i][cnt1] >= 0)
        return memo[i][cnt1];

      int res = 0;
      int up = is_limit ? s[i] - '0' : 9;
      for (int d = 0; d <= up; ++d)
        res += dfs(i + 1, cnt1 + (d == 1), is_limit && d == up);

      if (!is_limit)
        memo[i][cnt1] = res;

      return res;
    };

    return dfs(0, 0, true);
  }
};