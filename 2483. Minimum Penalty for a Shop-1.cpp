class Solution {
public:
  int bestClosingTime(string customers) {
    int n = customers.size();

    vector<int> pref(n + 1, 0), suff(n + 1, 0);
    for (int i = 1; i <= n; ++i)
      pref[i] = pref[i - 1] + (customers[i - 1] == 'N' ? 1 : 0);
    for (int i = n - 1; i >= 0; --i)
      suff[i] = suff[i + 1] + (customers[i] == 'Y' ? 1 : 0);

    int res = -1, curMin = n;
    for (int i = 0; i <= n; ++i) {
      int p = pref[i] + suff[i];
      if (p < curMin) {
        curMin = p;
        res = i;
      }
    }

    return res;
  }
};