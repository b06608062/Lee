class Solution {
public:
  int minExtraChar(string s, vector<string> &dictionary) {
    unordered_set<string> uset(dictionary.begin(), dictionary.end());
    int n = s.size();
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      int best = 1 + dp[i - 1];
      for (int j = i; j >= 1; --j) {
        if (uset.count(s.substr(j - 1, i - j + 1)))
          best = min(best, dp[j - 1]);
      }
      dp[i] = best;
    }

    return dp[n];
  }
};