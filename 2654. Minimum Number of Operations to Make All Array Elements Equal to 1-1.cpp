// mark
// 1929
// 枚舉 Minimum Subarray with GCD 1
// 無法用 Sliding Window，因為 GCD 不具備可逆性
class Solution {
public:
  int minOperations(vector<int> &nums) {
    int n = nums.size();

    int cnt = 0;
    for (auto x : nums)
      if (x == 1)
        cnt++;
    if (cnt)
      return n - cnt;

    int res = n + 1;
    for (int i = 0; i < n; ++i) {
      if (res == 2)
        break;
      int g = nums[i];
      for (int j = i + 1; j < n; ++j) {
        if (j - i + 1 >= res)
          break;
        g = gcd(g, nums[j]);
        if (g == 1) {
          res = min(res, j - i + 1);
          break;
        }
      }
    }

    if (res == n + 1)
      return -1;

    res--;
    res += n - 1;

    return res;
  }
};