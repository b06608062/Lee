// mark
// 經典字符串 DP + 正規表達式
class Solution {
public:
  bool isMatch(string s, string p) {
    int m = p.size(), n = s.size();

    // dp[i][j] 代表 pattern 前 i 個字元是否能匹配 string 前 j 個字元
    // 宣告 m+1 x n+1 是為了處理「空字串」的情況 (index 0)
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    // Base case: 兩個空字串互相匹配
    dp[0][0] = true;

    // 初始化：處理 pattern 匹配空 string 的情況 (例如 "a*", "a*b*" 匹配 "")
    // 因為 * 可以代表 0 個前面的字元，所以我們檢查是否能透過 * 消除前一個字元
    for (int i = 2; i <= m; ++i)
      if (p[i - 1] == '*')
        // 如果目前是 *，其狀態取決於「跳過目前字元與前一個字元」後的結果
        dp[i][0] = dp[i - 2][0];

    // 開始填表，i 代表 pattern 的進度，j 代表 string 的進度
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j) {

        // 情況一：當前 pattern 字元是 '*'
        if (p[i - 1] == '*') {
          /** * 這裡有兩個路徑可以讓 dp[i][j] 為 true：
           * 1. 匹配 0 次 (dp[i-2][j])：把 "字元*" 整個當作不存在，看 pattern
           * 前兩格是否匹配。
           * 2. 匹配 1 次或多次：前提是 pattern 的前一個字元 (p[i-2]) 必須匹配
           * string 當前字元 (s[j-1])。 若匹配成功，則看 string
           * 的前一個位置是否已經跟「包含這個 * 的 pattern」匹配 (dp[i][j-1])。
           */
          if (dp[i - 2][j] ||
              ((p[i - 2] == '.' || p[i - 2] == s[j - 1]) && dp[i][j - 1])) {
            dp[i][j] = true;
          }
        }
        // 情況二：當前字元匹配 (或是 pattern 為 '.')
        else if (p[i - 1] == '.' || p[i - 1] == s[j - 1]) {
          // 狀態由左上角 (上一對字元) 轉移過來
          dp[i][j] = dp[i - 1][j - 1];
        }

        // 情況三：若以上皆非，dp[i][j] 保持預設的 false
      }

    return dp[m][n];
  }
};