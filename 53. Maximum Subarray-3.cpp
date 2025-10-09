// TLE
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int n = nums.size();

    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i)
      prefix[i] = prefix[i - 1] + nums[i - 1];

    int res = INT_MIN;
    for (int i = 0; i < n; ++i)
      for (int j = i; j < n; ++j)
        res = max(res, prefix[j + 1] - prefix[i]);

    return res;
  }
};