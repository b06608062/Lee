// KMP
class Solution {
public:
  int strStr(string haystack, string needle) {
    int m = haystack.size(), n = needle.size();
    if (m < n)
      return -1;

    vector<int> pi = lps(needle);

    int k = 0;
    for (int i = 0; i < m; ++i) {
      while (k > 0 && haystack[i] != needle[k])
        k = pi[k - 1];
      if (haystack[i] == needle[k]) {
        k++;
        if (k == n)
          return i - k + 1;
      }
    }

    return -1;
  }

  vector<int> lps(string &p) {
    int n = p.size();

    vector<int> pi(n, 0);
    int k = 0;
    for (int i = 1; i < n; ++i) {
      while (k > 0 && p[i] != p[k])
        k = pi[k - 1];
      if (p[i] == p[k])
        pi[i] = ++k;
    }

    return pi;
  }
};