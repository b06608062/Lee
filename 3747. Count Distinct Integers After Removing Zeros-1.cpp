// mark
// 1848
// 數位 + 組合數學
class Solution {
public:
  long long countDistinct(long long n) {
    string s = "";
    while (n) {
      int d = n % 10;
      s = char(d + '0') + s;
      n /= 10;
    }

    int m = s.size();
    long long res = 0, pow9 = 1;
    for (int i = 1; i <= m - 1; ++i) {
      pow9 *= 9;
      res += pow9;
    }

    for (int i = 0; i < m; ++i) {
      if (s[i] == '0')
        break;
      int v = s[i] - '0' - 1;
      if (i == m - 1)
        v++;
      res += v * pow9;
      pow9 /= 9;
    }

    return res;
  }
};