class Solution {
public:
  unordered_set<string> uset;
  vector<int> memo;
  int n;
  int minExtraChar(string s, vector<string> &dictionary) {
    n = s.size();

    uset = unordered_set<string>(dictionary.begin(), dictionary.end());
    memo = vector<int>(n + 1, -1);

    memo[n] = 0;
    return helper(s, 0);
  }

  int helper(string &s, int i) {
    if (memo[i] != -1)
      return memo[i];

    int best = 1 + helper(s, i + 1);
    for (int j = i; j < n; ++j)
      if (uset.count(s.substr(i, j - i + 1)))
        best = min(best, helper(s, j + 1));

    return memo[i] = best;
  }
};