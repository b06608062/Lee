class Solution {
public:
  int countValidSelections(vector<int> &nums) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int target = sum / 2;

    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i)
      pref[i] = pref[i - 1] + nums[i - 1];

    int res = 0;
    for (int i = 1; i <= n; ++i)
      if (nums[i - 1] == 0)
        if (sum % 2 == 0) {
          if (target - pref[i - 1] == 0)
            res += 2;
        } else if (abs(sum - pref[i - 1] * 2) == 1)
          res += 1;
    return res;
  }
};