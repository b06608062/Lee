// 滑動窗 DP
class Solution {
public:
  bool canReach(string s, int minJump, int maxJump) {
    if (s.back() == '1')
      return false;
    int n = s.size();

    vector<int> dp(n, 0);

    dp[0] = 1;
    int cnt = 0; // 目前窗口 [i - maxJump, i - minJump] 中可達點數量
    for (int i = 1; i < n; ++i) {
      if (i - minJump >= 0) // 新增右邊界
        cnt += dp[i - minJump];
      if (i - maxJump - 1 >= 0) // 移除左邊界
        cnt -= dp[i - maxJump - 1];
      dp[i] = (s[i] == '0' && cnt > 0);
    }

    return dp[n - 1];
  }
};
