class Solution {
public:
  string reverseWords(string s) {
    int n = s.size();

    unordered_set<char> uset({'a', 'e', 'i', 'o', 'u'});

    int cntV = 0;
    int i = 0, j = s.find(' ', 0);
    for (int i = 0; i < j; ++i)
      cntV += uset.count(s[i]) ? 1 : 0;

    i = j + 1;
    while (i < n) {
      j = s.find(' ', i);
      if (j == string::npos)
        j = n;
      int k = i, cnt = 0;
      while (k < j)
        cnt += uset.count(s[k++]) ? 1 : 0;
      if (cnt == cntV)
        reverse(s, i, j - 1);
      i = j + 1;
    }

    return s;
  }

  void reverse(string &s, int l, int r) {
    while (l < r)
      swap(s[l++], s[r--]);
  }
};