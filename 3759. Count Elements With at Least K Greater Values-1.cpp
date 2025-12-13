class Solution {
public:
  int countElements(vector<int> &nums, int k) {
    int n = nums.size();
    if (k == 0)
      return n;

    sort(nums.begin(), nums.end());
    int x = nums[n - k];
    int i = 0;
    while (i < n && nums[i] < x)
      i++;

    return i;
  }
};