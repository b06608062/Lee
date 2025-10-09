class Solution {
public:
  int minExtraChar(string s, vector<string> &dictionary) {
    int n = s.size();

    unordered_set<string> uset(dictionary.begin(), dictionary.end());

    vector<int> dp(n + 1, 0);

    for (int i = n - 1; i >= 0; --i) {
      int best = 1 + dp[i + 1];
      for (int j = i; j < n; ++j)
        if (uset.count(s.substr(i, j - i + 1)))
          best = min(best, dp[j + 1]);
      dp[i] = best;
    }

    return dp[0];
  }
};