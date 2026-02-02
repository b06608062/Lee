class Solution {
public:
  int minimumK(vector<int> &nums) {
    int lo = 1, hi = INT_MAX;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (!isValid(nums, mid)) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }

    return lo;
  }

  bool isValid(vector<int> &nums, int k) {
    long long cnt = 0;
    for (auto x : nums) {
      cnt += (x + k - 1) / k;
    }

    return cnt <= 1ll * k * k;
  }
};