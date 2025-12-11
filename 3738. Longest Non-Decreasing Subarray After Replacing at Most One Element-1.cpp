// mark
// 1811
// 前後綴分解 Prefix + Suffix DP + 修改中點元素
class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    int n = nums.size();

    vector<int> left(n, 1), right(n, 1);

    int res = 2;
    for (int i = 1; i < n; ++i)
      if (nums[i] >= nums[i - 1])
        left[i] = left[i - 1] + 1;

    for (int i = n - 2; i >= 0; --i)
      if (nums[i] <= nums[i + 1])
        right[i] = right[i + 1] + 1;

    res = *max_element(left.begin(), left.end()) + 1;

    for (int i = 0; i + 2 < n; ++i)
      if (nums[i] <= nums[i + 2])
        res = max(res, left[i] + right[i + 2] + 1);

    return min(res, n);
  }
};