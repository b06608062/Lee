class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < abs(target) || (sum + target) % 2 != 0)
      return 0;
    int P = (sum + target) / 2;
    vector<int> f(P + 1, 0);
    f[0] = 1;
    for (auto x : nums)
      for (int i = P; i >= x; --i)
        f[i] += f[i - x];
    return f[P];
  }
};