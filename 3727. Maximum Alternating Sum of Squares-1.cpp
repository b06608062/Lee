class Solution {
public:
  long long maxAlternatingSum(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end(),
         [](auto &a, auto &b) { return abs(a) > abs(b); });

    int k = n % 2 ? n / 2 + 1 : n / 2;
    long long res = 0;
    for (int i = 0; i < n; ++i)
      res += i < k ? 1ll * nums[i] * nums[i] : -1ll * nums[i] * nums[i];

    return res;
  }
};