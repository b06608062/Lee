class Solution {
public:
  bool hasIncreasingSubarrays(vector<int> &nums, int k) {
    int n = nums.size();

    if (k == 1)
      return true;

    vector<bool> pos(n, false);

    int start = 0;
    for (int i = 1; i < n; ++i) {
      if (nums[i] <= nums[i - 1])
        start = i;
      if (i - start + 1 >= k)
        pos[i - k + 1] = true;
    }

    for (int i = 0; i + k - 1 < n; ++i)
      if (pos[i] && pos[i + k])
        return true;

    return false;
  }
};