// DP
class Solution {
public:
  bool canReach(string s, int minJump, int maxJump) {
    if (s.back() == '1')
      return false;
    int n = s.size();

    vector<int> dp(n, 0);

    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
      if (s[i] == '1')
        continue;
      int start = max(i - maxJump, 0);
      int end = i - minJump;
      for (int j = end; j >= start; --j) {
        if (dp[j]) {
          dp[i] = 1;
          break;
        }
      }
    }

    return dp[n - 1];
  }
};