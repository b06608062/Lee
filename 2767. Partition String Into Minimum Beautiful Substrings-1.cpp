class Solution {
public:
  int minimumBeautifulSubstrings(string s) {
    if (s[0] == '0')
      return -1;

    const int INF = INT_MAX / 2;
    int n = s.size();

    unordered_set<int> uset;
    int cur = 1;
    while (cur < 1e5) {
      uset.insert(cur);
      cur *= 5;
    }

    vector<int> dp(n + 1, INF);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == '0')
        continue;
      int cur = 0;
      for (int j = i; j < n; ++j) {
        cur <<= 1;
        cur |= s[j] - '0';
        if (uset.count(cur) && dp[j + 1] != INF)
          dp[i] = min(dp[i], dp[j + 1] + 1);
      }
    }

    return dp[0] == INF ? -1 : dp[0];
  }
};