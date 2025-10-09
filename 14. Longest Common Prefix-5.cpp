class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    return lcp(strs, 0, strs.size() - 1);
  }

  string lcp(vector<string> &strs, int l, int r) {
    if (l == r)
      return strs[l];

    int mid = l + (r - l) / 2;
    string left = lcp(strs, l, mid);
    string right = lcp(strs, mid + 1, r);

    return commonPrefix(left, right);
  }

  string commonPrefix(string &s1, string &s2) {
    int len = min(s1.size(), s2.size());
    int i = 0;
    while (i < len && s1[i] == s2[i])
      i++;

    return s1.substr(0, i);
  }
};
