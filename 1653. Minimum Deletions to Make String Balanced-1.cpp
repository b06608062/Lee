class Solution {
public:
  int minimumDeletions(string s) {
    int n = s.size();
    vector<int> pref_b(n + 1, 0), suff_a(n + 1, 0);

    // nxt a
    set<int> idx_a;
    int cnt_a = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'a') {
        cnt_a++;
        idx_a.insert(i);
      }
    }

    for (int i = 1; i <= n; ++i) {
      if (s[i - 1] == 'b') {
        pref_b[i] = pref_b[i - 1] + 1;
      } else {
        pref_b[i] = pref_b[i - 1];
      }
    }
    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == 'a') {
        suff_a[i] = suff_a[i + 1] + 1;
      } else {
        suff_a[i] = suff_a[i + 1];
      }
    }

    int res = n;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'a') {
        int cnt = pref_b[i];
        auto it = idx_a.lower_bound(i + 1);
        if (it != idx_a.end()) {
          cnt += suff_a[*it];
        }
        res = min(res, cnt);
      }
    }

    return min(cnt_a, (res == n) ? 0 : res);
  }
};