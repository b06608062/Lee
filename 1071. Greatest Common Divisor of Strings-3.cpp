class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
    int p1 = periodLen(str1), p2 = periodLen(str2);
    string base1 = str1.substr(0, p1);
    string base2 = str2.substr(0, p2);
    if (base1 != base2)
      return "";

    return str1.substr(0, gcd(str1.size(), str2.size()));
  }

  int periodLen(string &p) {
    int n = p.size();

    vector<int> pi(n, 0);
    int k = 0;
    for (int i = 1; i < n; ++i) {
      while (k > 0 && p[i] != p[k])
        k = pi[k - 1];
      if (p[i] == p[k])
        pi[i] = ++k;
    }

    int minP = n - pi[n - 1];
    return n % minP == 0 ? minP : n;
  }
};