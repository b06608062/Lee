class Solution {
public:
  vector<long long> pref;
  int n, encCost, flatCost;
  long long minCost(string s, int encCost, int flatCost) {
    int n = s.size();
    this->encCost = encCost, this->flatCost = flatCost;
    pref.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i)
      pref[i] = pref[i - 1] + (s[i - 1] - '0');
    return hepler(0, n - 1);
  }
  long long hepler(int l, int r) {
    if (l == r)
      return pref[l + 1] - pref[l] ? encCost : flatCost;
    long long L = r - l + 1;
    long long X = pref[r + 1] - pref[l];
    long long cost = X ? L * X * encCost : flatCost;
    if (L % 2 == 0)
      return min(cost, hepler(l, l + L / 2 - 1) + hepler(l + L / 2, r));
    return cost;
  }
};