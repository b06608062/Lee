// mark
// 1873
// 正方形構造題 + 哈希表配對
class Solution {
public:
  int maximizeSquareArea(int m, int n, vector<int> &hFences,
                         vector<int> &vFences) {
    const int MOD = 1e9 + 7;
    sort(hFences.begin(), hFences.end());
    sort(vFences.begin(), vFences.end());
    unordered_set<int> h_set;
    for (int i = 0; i < hFences.size(); ++i) {
      int top = i - 1 < 0 ? 1 : hFences[i - 1];
      int nt = i - 1 < 0 ? hFences[i] - 1 : hFences[i] - hFences[i - 1];
      h_set.insert(nt);
      for (int j = i; j < hFences.size(); ++j) {
        int bot = j + 1 >= hFences.size() ? m : hFences[j + 1];
        h_set.insert(bot - top);
      }
    }
    h_set.insert(m - hFences[hFences.size() - 1]);

    int mx = 0;
    for (int i = 0; i < vFences.size(); ++i) {
      int left = i - 1 < 0 ? 1 : vFences[i - 1];
      int nt = i - 1 < 0 ? vFences[i] - 1 : vFences[i] - vFences[i - 1];
      if (h_set.count(nt))
        mx = max(mx, nt);
      for (int j = i; j < vFences.size(); ++j) {
        int right = j + 1 >= vFences.size() ? n : vFences[j + 1];
        if (h_set.count(right - left))
          mx = max(mx, right - left);
      }
    }
    if (h_set.count(n - vFences[vFences.size() - 1]))
      mx = max(mx, n - vFences[vFences.size() - 1]);

    return mx ? 1ll * mx * mx % MOD : -1;
  }
};