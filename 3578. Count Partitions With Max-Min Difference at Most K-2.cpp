// mark
// 2033
// Deque 區間最大最小值 + 左邊界單調之滑窗 DP 前綴和
class Solution {
public:
  int countPartitions(vector<int> &nums, int k) {
    const int MOD = 1e9 + 7;
    int n = nums.size();
    vector<int> f(n + 1, 0);
    deque<int> small, big;

    f[0] = 1;
    int l = 0, r = 0, cur = 1;
    while (r < n) {
      int x = nums[r];
      while (!big.empty() && x >= nums[big.back()])
        big.pop_back();
      big.push_back(r);
      while (!small.empty() && x <= nums[small.back()])
        small.pop_back();
      small.push_back(r);
      while (nums[big.front()] - nums[small.front()] > k) {
        cur = ((cur - f[l]) % MOD + MOD) % MOD;
        l++;
        if (big.front() < l)
          big.pop_front();
        if (small.front() < l)
          small.pop_front();
      }
      f[r + 1] = cur;
      cur += f[r + 1];
      if (cur >= MOD)
        cur -= MOD;
      r++;
    }

    return f[n];
  }
};
