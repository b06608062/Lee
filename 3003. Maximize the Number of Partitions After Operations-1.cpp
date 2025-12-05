// mark
// 3039
// 字串 + 貪心 + 前後綴 DP 狀態壓縮
struct Node {
  int seg, mask, cnt;
};
class Solution {
public:
  int maxPartitionsAfterOperations(string s, int k) {
    if (k == 26)
      return 1;
    int n = s.size();

    vector<Node> pref(n), suff(n);

    int seg = 0, mask = 0, cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
      int x = s[i] - 'a';
      if ((mask >> x & 1) == 0) {
        if (++cnt > k) {
          seg++;
          mask = 0;
          cnt = 1;
        }
        mask |= 1 << x;
      }
      pref[i + 1] = {seg, mask, cnt};
    }

    seg = mask = cnt = 0;
    for (int i = n - 1; i > 0; --i) {
      int x = s[i] - 'a';
      if ((mask >> x & 1) == 0) {
        if (++cnt > k) {
          seg++;
          mask = 0;
          cnt = 1;
        }
        mask |= 1 << x;
      }
      suff[i - 1] = {seg, mask, cnt};
    }

    // pref[i] = s[0 ... i - 1]
    // suff[i] = s[i + 1 ... n - 1]
    // 估算最多可能切出多少段
    int res = 0;
    for (int i = 0; i < n; ++i) {
      auto [segL, maskL, cntL] = pref[i];
      auto [segR, maskR, cntR] = suff[i];
      mask = maskL | maskR;
      int bc = __builtin_popcount(mask);
      int add = (bc + 1) <= k ? 1 : (cntL == k && cntR == k && bc < 26) ? 3 : 2;
      res = max(res, segL + segR + add);
    }

    return res;
  }
};