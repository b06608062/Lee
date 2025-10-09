class Solution {
public:
  int zigZagArrays(int n, int l, int r) {
    constexpr int MOD = 1'000'000'007;
    const int m = r - l + 1;

    vector<int> up(m, 1), dn(m, 1);

    for (int i = 2; i <= n; ++i) {
      int pre = 0;
      for (int j = 0; j < m; ++j) {
        int v = dn[j];
        dn[j] = pre;
        pre += v;
        if (pre >= MOD)
          pre -= MOD;
      }

      int suf = 0;
      for (int j = m - 1; j >= 0; --j) {
        int v = up[j];
        up[j] = suf;
        suf += v;
        if (suf >= MOD)
          suf -= MOD;
      }

      up.swap(dn);
    }

    int res = 0;
    for (int j = 0; j < m; ++j) {
      res += up[j];
      if (res >= MOD)
        res -= MOD;
      res += dn[j];
      if (res >= MOD)
        res -= MOD;
    }
    return res;
  }
};
