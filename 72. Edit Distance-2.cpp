class Solution {
public:
  int minDistance(string word1, string word2) {
    if (word1.size() < word2.size())
      swap(word1, word2);
    int m = word1.size(), n = word2.size();

    vector<int> dp(n + 1, 0);
    for (int j = 1; j <= n; ++j)
      dp[j] = j;

    for (int i = 1; i <= m; ++i) {
      int diag = dp[0];
      dp[0] = i;
      for (int j = 1; j <= n; ++j) {
        int up = dp[j];
        if (word1[i - 1] == word2[j - 1])
          dp[j] = diag;
        else {
          int I = dp[j - 1] + 1;
          int D = up + 1;
          int R = diag + 1;
          dp[j] = min(I, min(D, R));
        }
        diag = up;
      }
    }

    return dp[n];
  }
};