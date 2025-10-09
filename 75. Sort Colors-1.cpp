class Solution {
public:
  void sortColors(vector<int> &nums) {
    int n = nums.size();

    int l = -1, r = n;
    for (int i = 0; i < r; ++i)
      if (nums[i] == 0)
        swap(nums[++l], nums[i]);
      else if (nums[i] == 2)
        swap(nums[--r], nums[i--]);
  }
};