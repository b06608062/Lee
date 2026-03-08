class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2)
      return false;
    int target = sum / 2;
    vector<bool> f(target + 1, false);
    f[0] = true;
    for (auto x : nums)
      for (int i = target; i >= x; --i)
        if (f[i - x])
          f[i] = true;
    return f[target];
  }
};