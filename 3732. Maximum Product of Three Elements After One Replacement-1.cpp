class Solution {
public:
  long long maxProduct(vector<int> &nums) {
    sort(nums.begin(), nums.end(),
         [](auto &a, auto &b) { return abs(a) > abs(b); });

    return abs(1LL * 1e5 * nums[0] * nums[1]);
  }
};