class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    int minLen = INT_MAX;
    for (auto &s : strs)
      minLen = min(minLen, (int)s.size());

    int l = 1, r = minLen + 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (helper(strs, m))
        l = m + 1;
      else
        r = m;
    }

    return strs[0].substr(0, l - 1);
  }

  bool helper(vector<string> &strs, int len) {
    // for (int i = 1; i < strs.size(); ++i)
    //   for (int j = 0; j < len; ++j)
    //     if (strs[i][j] != strs[0][j])
    //       return false;

    for (int i = 1; i < strs.size(); ++i)
      if (strs[i].compare(0, len, strs[0], 0, len) != 0) // < 0, = 0, > 0
        return false;

    return true;
  }
};