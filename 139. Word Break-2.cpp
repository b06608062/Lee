class Solution {
public:
  int n;
  unordered_set<string> uset;
  vector<int> memo;
  bool wordBreak(string s, vector<string> &wordDict) {
    n = s.size();

    uset = unordered_set<string>(wordDict.begin(), wordDict.end());
    memo = vector<int>(n + 1, -1);

    memo[n] = 1;
    return helper(s, 0);
  }

  bool helper(string &s, int i) {
    if (memo[i] != -1)
      return memo[i];

    for (int j = i; j < n; ++j)
      if (uset.count(s.substr(i, j - i + 1)) && helper(s, j + 1))
        return memo[i] = 1;

    return memo[i] = 0;
  }
};