class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    int n = nums.size();
    // x -> pos x - 1
    for (int i = 0; i < n; ++i) {
      int x = nums[i];
      while (x >= 1 && x <= n && x - 1 != i) {
        int y = nums[x - 1];
        if (x == y)
          break;
        swap(nums[i], nums[x - 1]);
        x = y;
      }
    }
    for (int i = 1; i <= n; ++i)
      if (nums[i - 1] != i)
        return i;
    return n + 1;
  }
};