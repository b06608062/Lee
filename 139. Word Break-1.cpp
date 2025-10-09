class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    int n = s.size();

    unordered_set<string> uset(wordDict.begin(), wordDict.end());
    vector<int> dp(n + 1, 0);

    dp[n] = 1;
    for (int i = n - 1; i >= 0; --i)
      for (int j = i; j < n; ++j)
        if (uset.count(s.substr(i, j - i + 1)) && dp[j + 1])
          dp[i] = 1;

    return dp[0];
  }
};