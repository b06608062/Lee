// mark
// 垂直掃描
class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    int n = strs.size();
    int mn = INT_MAX;
    for (auto &s : strs)
      mn = min(mn, (int)s.size());
    string res = "";
    for (int i = 0; i < mn; ++i) {
      for (int j = 1; j < n; ++j)
        if (strs[j][i] != strs[j - 1][i])
          return res;
      res += strs[0][i];
    }
    return res;
  }
};

// 水平掃描
class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    int n = strs.size();
    int mn = INT_MAX;
    for (auto &s : strs)
      mn = min(mn, (int)s.size());
    for (int i = 1; i < n; ++i)
      while (strs[i].substr(0, mn) != strs[0].substr(0, mn))
        mn--;
    return strs[0].substr(0, mn);
  }
};

// 二分搜尋法
class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    int n = strs.size();
    int mn = INT_MAX;
    for (auto &s : strs)
      mn = min(mn, (int)s.size());
    int lo = 0, hi = mn + 1;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (helper(strs, mid))
        lo = mid + 1;
      else
        hi = mid;
    }
    return strs[0].substr(0, lo - 1);
  }
  bool helper(vector<string> &strs, int mid) {
    int n = strs.size();
    for (int i = 1; i < n; ++i)
      if (strs[i].substr(0, mid) != strs[0].substr(0, mid))
        return false;
    return true;
  }
};

// 排序法
class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    sort(strs.begin(), strs.end());
    string res = "";
    string first = strs[0], last = strs[strs.size() - 1];
    int i;
    for (i = 0; i < min(first.size(), last.size()); ++i)
      if (first[i] != last[i])
        break;
    return first.substr(0, i);
  }
};

// 分治法 LCP
class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    int n = strs.size();
    return helper(strs, 0, n - 1);
  }
  string helper(vector<string> &strs, int l, int r) {
    if (l == r)
      return strs[l];
    int m = l + (r - l) / 2;
    auto s_l = helper(strs, l, m);
    auto s_r = helper(strs, m + 1, r);
    return lcp(s_l, s_r);
  }
  string lcp(string &s, string &t) {
    int mn = min(s.size(), t.size());
    int i = 0;
    for (; i < mn; ++i)
      if (s[i] != t[i])
        break;
    return s.substr(0, i);
  }
};