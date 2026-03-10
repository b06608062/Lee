class Solution {
public:
  int numDistinct(string s, string t) {
    int m = s.size(), n = t.size();
    vector<unsigned int> f(n + 1, 0);
    f[0] = 1;

    for (int i = 1; i <= m; ++i) {
      for (int j = n; j >= 1; --j)
        if (s[i - 1] == t[j - 1])
          f[j] += f[j - 1];
    }
    return f[n];
  }
};

class Solution {
public:
  int numDistinct(string s, string t) {
    int m = s.size(), n = t.size();
    vector<unsigned int> f(n + 1, 0);
    f[0] = 1;

    for (int i = 1; i <= m; ++i) {
      int diag = 1;
      for (int j = 1; j <= n; ++j) {
        int up = f[j];
        if (s[i - 1] == t[j - 1])
          f[j] += diag;
        diag = up;
      }
    }
    return f[n];
  }
};