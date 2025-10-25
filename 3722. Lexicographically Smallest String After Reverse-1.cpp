class Solution {
public:
  string lexSmallest(string s) {
    int n = s.size();

    string res = s;
    for (int k = 1; k <= n; ++k) {
      string rev1 = s, rev2 = s;
      reverse(rev1.begin(), rev1.begin() + k);
      reverse(rev2.begin() + n - k, rev2.end());
      if (rev1 < res)
        res = rev1;
      if (rev2 < res)
        res = rev2;
    }

    return res;
  }
};