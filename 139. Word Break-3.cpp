class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    int n = s.size();

    unordered_set<string> uset(wordDict.begin(), wordDict.end());
    vector<int> dp(n + 1, 0);

    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
      for (int j = i; j >= 1; --j)
        if (uset.count(s.substr(j - 1, i - j + 1)) && dp[j - 1])
          dp[i] = 1;

    return dp[n];
  }
};