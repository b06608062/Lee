class Solution {
public:
  long long splitArray(vector<int> &nums) {
    int n = nums.size();

    vector<long long> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i)
      pref[i] = pref[i - 1] + nums[i - 1];

    vector<long long> suff(n + 1, 0);
    for (int i = n - 1; i >= 0; --i)
      suff[i] = suff[i + 1] + nums[i];

    int i = 0;
    while (i + 1 < n) {
      if (nums[i] >= nums[i + 1])
        break;
      i++;
    }

    if (i == n - 1)
      return abs(pref[n - 1] - suff[n - 1]);

    int j = i + 1;
    while (j + 1 < n) {
      if (nums[j] <= nums[j + 1])
        return -1;
      j++;
    }

    // i | i + 1
    if (nums[i] == nums[i + 1])
      return abs(pref[i + 1] - suff[i + 1]);

    // i - 1 | i or i | i + 1
    return min(abs(pref[i] - suff[i]), abs(pref[i + 1] - suff[i + 1]));
  }
};