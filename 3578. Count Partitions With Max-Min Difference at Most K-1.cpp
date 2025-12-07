// mark
// 2033
// Deque 區間最大最小值 + 前綴和 DP
class Solution {
public:
  int countPartitions(vector<int> &nums, int k) {
    const int MOD = 1e9 + 7;
    int n = nums.size();
    vector<int> dp(n, 0), pref(n + 2, 0), left(n, 0);

    deque<int> small, big;
    int l = 0, r = 0;
    while (r < n) {
      int x = nums[r];
      while (!big.empty() && x >= nums[big.back()])
        big.pop_back();
      big.push_back(r);
      while (!small.empty() && x <= nums[small.back()])
        small.pop_back();
      small.push_back(r);
      while (nums[big.front()] - nums[small.front()] > k) {
        l++;
        if (big.front() < l)
          big.pop_front();
        if (small.front() < l)
          small.pop_front();
      }
      left[r] = l;
      r++;
    }

    pref[0] = 0, pref[1] = 1;
    int cur = 1;
    for (int i = 0; i < n; ++i) {
      int l = left[i];
      dp[i] = ((cur - pref[l]) % MOD + MOD) % MOD;
      cur += dp[i];
      if (cur >= MOD)
        cur -= MOD;
      pref[i + 2] = cur;
    }

    return dp[n - 1];
  }
};
