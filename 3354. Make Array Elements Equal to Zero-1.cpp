class Solution {
public:
  int countValidSelections(vector<int> &nums) {
    int n = nums.size();
    vector<int> pref(n + 1, 0), suff(n + 1, 0);
    ;
    for (int i = 1; i <= n; ++i)
      pref[i] = pref[i - 1] + nums[i - 1];
    for (int i = n - 1; i >= 0; --i)
      suff[i] = suff[i + 1] + nums[i];

    int res = 0;
    for (int i = 0; i < n; ++i)
      if (nums[i] == 0)
        if (pref[i + 1] == suff[i])
          res += 2;
        else if (abs(pref[i + 1] - suff[i]) == 1)
          res += 1;

    return res;
  }
};