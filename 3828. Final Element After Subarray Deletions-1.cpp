// mark
// 1591
// 腦筋急轉彎
// Alice 不可能取到中間比較大的數字

class Solution {
public:
  int finalElement(vector<int> &nums) {
    return max(nums[0], nums[nums.size() - 1]);
  }
};