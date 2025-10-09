class Solution {
public:
  long long maxTotalValue(vector<int> &nums, int k) {
    int maxVal = INT_MIN, minVal = INT_MAX;
    for (auto x : nums) {
      maxVal = max(maxVal, x);
      minVal = min(minVal, x);
    }

    return (long long)(maxVal - minVal) * k;
  }
};