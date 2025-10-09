class Solution {
public:
  int distinctPoints(string s, int k) {
    int n = s.size();

    vector<pair<int, int>> pref(n + 1, {0, 0});
    for (int i = 1; i <= n; ++i) {
      pref[i] = pref[i - 1];
      if (s[i - 1] == 'U')
        pref[i].second++;
      else if (s[i - 1] == 'D')
        pref[i].second--;
      else if (s[i - 1] == 'L')
        pref[i].first--;
      else
        pref[i].first++;
    }

    vector<pair<int, int>> suff(n + 1, {0, 0});
    for (int i = n - 1; i >= 0; --i) {
      suff[i] = suff[i + 1];
      if (s[i] == 'U')
        suff[i].second++;
      else if (s[i] == 'D')
        suff[i].second--;
      else if (s[i] == 'L')
        suff[i].first--;
      else
        suff[i].first++;
    }

    set<pair<int, int>> sset;

    for (int i = 0; i + k <= n; ++i)
      sset.insert({pref[i].first + suff[i + k].first,
                   pref[i].second + suff[i + k].second});

    return sset.size();
  }
};