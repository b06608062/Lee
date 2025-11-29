class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    int minValue = *min_element(nums.begin(), nums.end());
    int maxValue = *max_element(nums.begin(), nums.end());
    int range = maxValue - minValue + 1;

    vector<int> count(range, 0);

    for (auto x : nums) {
      count[x - minValue]++;
    }

    for (int i = range - 1; i >= 0; --i) {
      k -= count[i];
      if (k <= 0)
        return i + minValue;
    }

    return -1;
  }
};