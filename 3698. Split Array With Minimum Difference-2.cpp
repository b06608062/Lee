class Solution {
public:
  long long splitArray(vector<int> &nums) {
    int n = nums.size();

    vector<long long> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i)
      pref[i] = pref[i - 1] + nums[i - 1];

    int l = 1;
    while (l < n) {
      if (nums[l] > nums[l - 1])
        l++;
      else
        break;
    }

    int r = n - 2;
    while (r >= 0) {
      if (nums[r] > nums[r + 1])
        r--;
      else
        break;
    }

    if (l <= r)
      return -1;

    if (l - r == 1)
      return abs((pref[l] - pref[0]) - (pref[n] - pref[r + 1]));

    return min(abs((pref[l - 1] - pref[0]) + nums[(l + r) / 2] -
                   (pref[n] - pref[r + 2])),
               abs((pref[l - 1] - pref[0]) - nums[(l + r) / 2] -
                   (pref[n] - pref[r + 2])));
  }
};