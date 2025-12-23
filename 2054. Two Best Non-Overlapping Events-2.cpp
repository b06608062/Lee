class Solution {
public:
  int maxTwoEvents(vector<vector<int>> &events) {
    int n = events.size();

    sort(events.begin(), events.end(),
         [](auto &a, auto &b) { return a[1] < b[1]; });

    vector<int> pref(n);

    pref[0] = events[0][2];
    for (int i = 1; i < n; ++i)
      pref[i] = max(pref[i - 1], events[i][2]);

    int res = 0;
    for (int i = 0; i < n; ++i) {
      int st = events[i][0], v = events[i][2];

      int l = 0, r = i;
      while (l < r) {
        int m = l + (r - l) / 2;
        if (events[m][1] < st) {
          l = m + 1;
        } else {
          r = m;
        }
      }
      res = max(res, v + (l == 0 ? 0 : pref[l - 1]));
    }

    return res;
  }
};
