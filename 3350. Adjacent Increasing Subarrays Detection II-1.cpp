class Solution {
public:
  int maxIncreasingSubarrays(vector<int> &nums) {
    int n = nums.size();

    vector<int> ics(n, 1);

    for (int i = 1; i < n; ++i)
      if (nums[i] > nums[i - 1])
        ics[i] = ics[i - 1] + 1;

    auto validK = [&](int k) {
      for (int i = 0; i + k < n; ++i)
        if (ics[i] >= k && ics[i + k] >= k)
          return true;
      return false;
    };

    int lo = 2, hi = n + 1;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (validK(mid))
        lo = mid + 1;
      else
        hi = mid;
    }

    return lo - 1;
  }
};