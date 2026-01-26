// mark
// 1301
// Greedy + Sorting
// 將陣列排序後，兩兩配對使得最大值最小化
class Solution {
public:
  int minPairSum(vector<int> &nums) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    int res = 0;
    for (int i = 0; i < n / 2; ++i) {
      res = max(res, nums[i] + nums[n - 1 - i]);
    }

    return res;
  }
};