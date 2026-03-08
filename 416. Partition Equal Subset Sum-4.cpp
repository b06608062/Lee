class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2)
      return false;

    int target = sum / 2;
    bitset<20001> f;
    f[0] = 1;
    for (auto x : nums)
      f |= f << x;

    return f[target];
  }
};