class Solution {
public:
  int distinctPoints(string s, int k) {
    int n = s.size();

    set<pair<int, int>> sset;
    pair<int, int> p = {0, 0};
    for (auto ch : s)
      helper(p, ch, 1);

    int i = 0, j = 0;
    while (j < n) {
      helper(p, s[j], -1);
      if (j >= k)
        helper(p, s[i++], 1);
      if (j >= k - 1)
        sset.insert(p);
      j++;
    }

    return sset.size();
  }

  void helper(pair<int, int> &p, char ch, int dir = 1) {
    auto &[x, y] = p;
    if (ch == 'U')
      y += dir;
    else if (ch == 'D')
      y -= dir;
    else if (ch == 'L')
      x -= dir;
    else
      x += dir;
  }
};