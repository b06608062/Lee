class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
    while (!str1.empty() && !str2.empty()) {
      int m = str1.size(), n = str2.size();
      if (m >= n) {
        if (str1.substr(0, n) != str2)
          return "";
        str1 = str1.substr(n, m - n);
      } else {
        if (str2.substr(0, m) != str1)
          return "";
        str2 = str2.substr(m, n - m);
      }
    }

    return str1.empty() ? str2 : str1;
  }
};