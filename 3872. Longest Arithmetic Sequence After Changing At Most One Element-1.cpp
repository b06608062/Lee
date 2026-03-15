// mark
// ???
// 前後綴分解 + 嘗試修改中間一個元素

class Solution {
public:
  int longestArithmetic(vector<int> &nums) {
    int n = nums.size();
    if (n <= 2)
      return n;

    vector<int> L(n, 1), R(n, 1);

    for (int i = 1; i < n; ++i) {
      if (i >= 2 && nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
        L[i] = L[i - 1] + 1;
      else
        L[i] = 2;
    }

    for (int i = n - 2; i >= 0; --i) {
      if (i <= n - 3 && nums[i + 1] - nums[i] == nums[i + 2] - nums[i + 1])
        R[i] = R[i + 1] + 1;
      else
        R[i] = 2;
    }

    int res = 2;
    for (int i = 0; i < n; ++i) {
      if (i + 1 < n)
        res = max(res, L[i] + 1);
      if (i - 1 >= 0)
        res = max(res, R[i] + 1);
    }

    for (int i = 1; i < n - 1; ++i) {
      if ((nums[i + 1] - nums[i - 1]) % 2 == 0) {
        int d = (nums[i + 1] - nums[i - 1]) / 2;
        int left_part =
            (i >= 2 && nums[i - 1] - nums[i - 2] == d) ? L[i - 1] : 1;
        int right_part =
            (i <= n - 3 && nums[i + 2] - nums[i + 1] == d) ? R[i + 1] : 1;
        res = max(res, left_part + 1 + right_part);
      }
    }

    return min(res, n);
  }
};