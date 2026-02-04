// mark
// 2278
// 分組循環找規律

class Solution {
public:
  long long maxSumTrionic(vector<int> &nums) {
    int n = nums.size();

    long long res = LLONG_MIN;
    for (int i = 0; i < n;) {
      int start = i;
      // 第一段
      for (i = start + 1; i < n; ++i) {
        if (nums[i - 1] >= nums[i]) {
          break;
        }
      }
      if (i == start + 1) { // 第一段至少要兩個數
        continue;
      }

      // 第二段
      int peak = i - 1;
      long long cur = nums[peak - 1] + nums[peak]; // 第一段的最後兩數必選
      for (; i < n; ++i) {
        if (nums[i - 1] <= nums[i]) {
          break;
        }
        cur += nums[i]; // 第二段所有數必選
      }
      if (i == peak + 1 || i == n ||
          nums[i - 1] == nums[i]) { // 第二段 & 第三段至少要兩個數
        continue;
      }

      int bottom = i - 1;
      cur += nums[i]; // 第三段的前兩數必選，第三段第一個數已在第二段累加

      long long max_s = 0, s = 0;
      for (i++; i < n; ++i) {
        if (nums[i - 1] >= nums[i]) {
          break;
        }
        s += nums[i];
        max_s = max(max_s, s);
      }
      cur += max_s;

      max_s = 0, s = 0;
      for (i = peak - 2; i >= start; --i) {
        s += nums[i];
        max_s = max(max_s, s);
      }
      cur += max_s;

      res = max(res, cur);
      i = bottom;
    }
    return res;
  }
};