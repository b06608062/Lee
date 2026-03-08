class Solution {
public:
  int maxProduct(vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    return divideAndConquer(nums, 0, nums.size() - 1);
  }

private:
  int divideAndConquer(vector<int> &nums, int left, int right) {
    if (left == right)
      return nums[left];

    int mid = left + (right - left) / 2;

    int leftMax = divideAndConquer(nums, left, mid);
    int rightMax = divideAndConquer(nums, mid + 1, right);

    int crossMax = maxCrossing(nums, left, mid, right);

    return max({leftMax, rightMax, crossMax});
  }

  int maxCrossing(vector<int> &nums, int left, int mid, int right) {
    int l_max = INT_MIN, l_min = INT_MAX;

    int cur = 1;
    for (int i = mid; i >= left; --i) {
      cur *= nums[i];
      l_max = max(l_max, cur);
      l_min = min(l_min, cur);
      if (cur == 0)
        break;
    }

    int r_max = INT_MIN, r_min = INT_MAX;
    cur = 1;
    for (int i = mid + 1; i <= right; ++i) {
      cur *= nums[i];
      r_max = max(r_max, cur);
      r_min = min(r_min, cur);
      if (cur == 0)
        break;
    }

    int res = max(l_max * r_max, l_min * r_min);

    return res;
  }
};