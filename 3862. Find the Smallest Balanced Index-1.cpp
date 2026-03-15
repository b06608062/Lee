// mark
// 1697
// pref + suff
// 防止乘法 overflow 的技巧是 A * B > MAX => A > MAX / B
// 處理 suff 超過 sum 時，後面又有 0 的情況，suff 會一直是 0，所以要特別處理

class Solution {
public:
  int smallestBalancedIndex(vector<int> &nums) {
    int n = nums.size();
    long long sum = accumulate(nums.begin(), nums.end(), 0ll);
    vector<long long> pref(n, 0), suff(n, -1);
    for (int i = 1; i < n; ++i)
      pref[i] = pref[i - 1] + nums[i - 1];

    suff[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
      if (suff[i + 1] > sum / nums[i + 1]) {
        while (i >= -1 && nums[i + 1] != 0)
          i--;
        while (i >= 0)
          suff[i--] = 0;
      } else {
        suff[i] = suff[i + 1] * nums[i + 1];
      }
    }

    for (int i = 0; i < n; ++i)
      if (pref[i] == suff[i])
        return i;
    return -1;
  }
};