class Solution {
public:
  int countElements(vector<int> &nums, int k) {
    int n = nums.size();
    if (k == 0)
      return n;

    sort(nums.begin(), nums.end());
    int i = n - 2;
    while (i >= 0) {
      if (nums[i] != nums[i + 1]) {
        if (n - 1 - i >= k)
          break;
      }
      i--;
    }

    return i + 1;
  }
};