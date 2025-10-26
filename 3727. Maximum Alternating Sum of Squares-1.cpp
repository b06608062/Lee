class Solution {
public:
  long long maxAlternatingSum(vector<int> &nums) {
    int n = nums.size();

    for (auto &x : nums)
      x = abs(x);
    sort(nums.rbegin(), nums.rend());

    int even = (n + 1) / 2;
    long long res = 0;
    for (int i = 0; i < n; ++i) {
      long long x = (long long)nums[i] * nums[i];
      if (i < even)
        res += x;
      else
        res -= x;
    }

    return res;
  }
};