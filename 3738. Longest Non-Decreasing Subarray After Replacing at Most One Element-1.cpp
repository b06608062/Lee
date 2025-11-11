class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    int n = nums.size();
    if (n <= 2)
      return n;

    int l = 0, r = 1, last = -1, temp = -1, res = 1;
    while (r < n) {
      if (nums[r] < nums[r - 1]) {
        if (last == -1) {
          temp = nums[r], last = r;
          nums[r] = nums[r - 1];
        } else {
          nums[last] = temp;
          l = last;
          temp = -1, last = -1;
          continue;
        }
      }
      res = max(res, r - l + 1);
      r++;
    }

    if (last != -1)
      nums[last] = temp;

    l = n - 2, r = n - 1, last = -1, temp = -1;
    while (l >= 0) {
      if (nums[l] > nums[l + 1]) {
        if (last == -1) {
          temp = nums[l], last = l;
          nums[l] = nums[l + 1];
        } else {
          nums[last] = temp;
          r = last;
          temp = -1, last = -1;
          continue;
        }
      }
      res = max(res, r - l + 1);
      l--;
    }

    return res;
  }
};