class Solution {
public:
  int findMaxLength(vector<int> &nums) {
    int n = nums.size();

    vector<int> first(2 * n + 1, INT_MAX / 2);
    int offset = n;
    int diff = 0, res = 0;
    first[offset + 0] = -1;
    for (int i = 0; i < n; ++i) {
      diff += (nums[i] ? 1 : -1);
      int idx = offset + diff;
      if (first[idx] == INT_MAX / 2)
        first[idx] = i;
      else
        res = max(res, i - first[idx]);
    }

    return res;
  }
};