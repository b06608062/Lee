class Solution {
public:
  int maximizeSquareHoleArea(int n, int m, vector<int> &hBars,
                             vector<int> &vBars) {
    // 1, n + 2
    // 1, m + 2
    sort(hBars.begin(), hBars.end());
    sort(vBars.begin(), vBars.end());

    int cur = 1, cnth = 1, cntv = 1;
    for (int i = 1; i < hBars.size(); ++i)
      if (hBars[i] == hBars[i - 1] + 1) {
        cur++;
        cnth = max(cnth, cur);
      } else {
        cur = 1;
      }
    cur = 1;
    for (int j = 1; j < vBars.size(); ++j)
      if (vBars[j] == vBars[j - 1] + 1) {
        cur++;
        cntv = max(cntv, cur);
      } else {
        cur = 1;
      }

    return (min(cnth, cntv) + 1) * (min(cnth, cntv) + 1);
  }
};