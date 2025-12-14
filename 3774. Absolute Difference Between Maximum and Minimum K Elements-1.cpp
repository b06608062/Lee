// mark
// 線性時間 + 排序
// O(n log n)
class Solution {
public:
  int absDifference(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());

    return abs(accumulate(nums.begin(), nums.begin() + k, 0) -
               accumulate(nums.rbegin(), nums.rbegin() + k, 0));
  }
};

// O(n)
class Solution {
public:
  int absDifference(vector<int> &nums, int k) {
    ranges::nth_element(nums, nums.end() - k);
    int res = reduce(nums.end() - k, nums.end());
    ranges::nth_element(nums, nums.begin() + k);
    return res - reduce(nums.begin(), nums.begin() + k);
  }
};