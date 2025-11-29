class Solution {
public:
  int splitArray(vector<int> &nums, int k) {
    int lo = *max_element(nums.begin(), nums.end());
    int hi = accumulate(nums.begin(), nums.end(), 0);
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (!valid(nums, k, mid))
        lo = mid + 1;
      else
        hi = mid;
    }

    return lo;
  }

  bool valid(vector<int> &nums, int k, int maxSum) {
    int cnt = 1, cur = maxSum;
    for (auto x : nums)
      if (x <= cur)
        cur -= x;
      else {
        cur = maxSum - x;
        cnt++;
      }

    return cnt <= k;
  }
};