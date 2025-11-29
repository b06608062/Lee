class Solution {
public:
  bool isSubsequence(string s, string t) {
    int m = s.size(), n = t.size();

    int j = 0;
    for (int i = 0; i < n && j < m; ++i)
      if (t[i] == s[j])
        j++;

    return j == m;
  }
};

// s 裡可以刪掉一段連續 substring，刪完之後 t 還是 s 的 subsequence，問這段
// substring 最長多長
int maxDeletableSubstring(const string &s, const string &t) {
  int n = s.size();
  int m = t.size();

  // t 已知是 s 的 subsequence，不特別檢查
  vector<int> L(m), R(m);

  // 從左到右：紀錄每個 t[i] 最早匹配到的 s 的位置
  int p = 0;
  for (int i = 0; i < n && p < m; ++i) {
    if (s[i] == t[p]) {
      L[p] = i;
      ++p;
    }
  }

  // 從右到左：紀錄每個 t[i] 最晚匹配到的 s 的位置
  int q = m - 1;
  for (int i = n - 1; i >= 0 && q >= 0; --i) {
    if (s[i] == t[q]) {
      R[q] = i;
      --q;
    }
  }

  int ans = 0;

  // 情況1：只保留 t 的 suffix，刪掉前面的 prefix
  // 刪 s[0..R[0]-1]，長度為 R[0]
  ans = max(ans, R[0]);

  // 情況2：只保留 t 的 prefix，刪掉後面的 suffix
  // 刪 s[L[m-1]+1..n-1]，長度為 n - 1 - L[m-1]
  ans = max(ans, n - 1 - L[m - 1]);

  // 情況3：保留 t[0..i-1] + t[i..m-1]，中間刪掉一段
  // 中間可刪 s[L[i-1]+1..R[i]-1]，長度 R[i]-L[i-1]-1
  for (int i = 1; i < m; ++i) {
    ans = max(ans, R[i] - L[i - 1] - 1);
  }

  return ans;
}