class Solution {
public:
  string longestPalindrome(string s) {
    string t = "$#";
    for (char &ch : s) {
      t += ch;
      t += '#';
    }
    t += "@";
    int n = t.size();
    vector<int> p(n, 0);
    int C = 0, R = 0;
    int mx_l = 0, c_idx = 0;
    for (int i = 1; i < n - 1; ++i) {
      if (i < R)
        p[i] = min(R - i, p[2 * C - i]);
      while (t[i + (1 + p[i])] == t[i - (1 + p[i])])
        p[i]++;
      if (i + p[i] > R)
        C = i, R = i + p[i];
      if (p[i] > mx_l) {
        mx_l = p[i];
        c_idx = i;
      }
    }

    // i -> 2i + 2
    int start = ((c_idx - mx_l + 1) - 2) / 2;
    return s.substr(start, mx_l);
  }
};