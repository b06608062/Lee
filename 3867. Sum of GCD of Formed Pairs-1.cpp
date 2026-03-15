class Solution {
public:
  long long gcdSum(vector<int> &nums) {
    int n = nums.size();
    vector<int> pref(n);
    int mx = INT_MIN;
    for (int i = 0; i < n; ++i) {
      int x = nums[i];
      mx = max(mx, x);
      pref[i] = gcd(x, mx);
    }
    sort(pref.begin(), pref.end());
    int l = 0, r = n - 1;
    long long res = 0;
    while (l < r)
      res += gcd(pref[l++], pref[r--]);
    return res;
  }
};