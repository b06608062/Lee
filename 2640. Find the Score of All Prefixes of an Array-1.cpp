class Solution {
public:
  vector<long long> findPrefixScore(vector<int> &nums) {
    int n = nums.size();

    vector<int> conver(n, 0);

    int curMax = INT_MIN;
    for (int i = 0; i < n; ++i) {
      curMax = max(curMax, nums[i]);
      conver[i] = nums[i] + curMax;
    }

    vector<long long> pref(n, 0);
    pref[0] = conver[0];
    for (int i = 1; i < n; ++i)
      pref[i] = pref[i - 1] + conver[i];

    return pref;
  }
};