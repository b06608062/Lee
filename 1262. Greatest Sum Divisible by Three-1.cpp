// mark
// 1762
// DP + MOD 狀態壓縮 + Subset Sum
class Solution {
public:
  int maxSumDivThree(vector<int> &nums) {
    int n = nums.size();
    vector<int> f(3, INT_MIN);
    f[0] = 0;

    for (auto x : nums) {
      auto f0 = f;
      for (int i = 0; i < 3; ++i) {
        if (f[i] == INT_MIN)
          continue;
        int r = (i + x) % 3;
        f[r] = max(f[r], f0[i] + x);
      }
    }

    return f[0];
  }
};