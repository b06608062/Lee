// TLE
class Solution {
public:
  bool canReach(string s, int minJump, int maxJump) {
    if (s.back() == '1')
      return false;
    int n = s.size();

    vector<int> dp(n, 0);

    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1' || !dp[i])
        continue;
      for (int j = i + minJump; j <= i + maxJump && j < n; ++j)
        if (s[j] == '0')
          dp[j] = 1;
    }

    return dp[n - 1];
  }
};