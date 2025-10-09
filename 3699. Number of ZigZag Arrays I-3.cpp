class Solution {
public:
  int zigZagArrays(int n, int l, int r) {
    constexpr int MOD = 1'000'000'007;
    const int m = r - l + 1;

    vector<int> upPrev(m, 1), dnPrev(m, 1), upCur(m), dnCur(m);

    for (int i = 2; i <= n; ++i) {
      int pref = 0;
      upCur[0] = 0;
      for (int j = 1; j < m; ++j) {
        pref += dnPrev[j - 1];
        if (pref >= MOD)
          pref -= MOD;
        upCur[j] = pref;
      }

      int suff = 0;
      dnCur[m - 1] = 0;
      for (int j = m - 2; j >= 0; --j) {
        suff += upPrev[j + 1];
        if (suff >= MOD)
          suff -= MOD;
        dnCur[j] = suff;
      }

      upPrev.swap(upCur);
      dnPrev.swap(dnCur);
    }

    int res = 0;
    for (int j = 0; j < m; ++j) {
      res += upPrev[j];
      if (res >= MOD)
        res -= MOD;
      res += dnPrev[j];
      if (res >= MOD)
        res -= MOD;
    }
    return res;
  }
};
