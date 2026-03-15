class Solution {
public:
  int minOperations(string s) {
    int n = s.size();
    if (n < 2)
      return 0;
    if (n == 2)
      return (s[0] <= s[1]) ? 0 : -1;

    char mn = s[0], mx = s[0];
    bool sorted = true;
    for (int i = 0; i < n; ++i) {
      if (i > 0 && s[i] < s[i - 1])
        sorted = false;
      mn = min(mn, s[i]);
      mx = max(mx, s[i]);
    }
    if (sorted)
      return 0;

    int mn_cnt = 0, mx_cnt = 0;
    for (char ch : s) {
      if (ch == mn)
        mn_cnt++;
      else if (ch == mx)
        mx_cnt++;
    }

    // 3. Case 1: 只要頭對了或尾對了
    if (s[0] == mn || s[n - 1] == mx)
      return 1;

    // 4. Case 3: 只有當頭是唯一的 mx 且 尾是唯一的 mn 時，才需要 3 步
    if (s[0] == mx && mx_cnt == 1 && s[n - 1] == mn && mn_cnt == 1) {
      return 3;
    }

    // 5. 其他所有情況 (包含 "jgg")
    return 2;
  }
};