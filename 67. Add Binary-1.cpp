class Solution {
public:
  string addBinary(string a, string b) {
    int m = a.size(), n = b.size();

    string res;
    int i = m - 1, j = n - 1, carry = 0;
    while (i >= 0 || j >= 0 || carry) {
      if (i >= 0) {
        carry += a[i] - '0';
        i--;
      }
      if (j >= 0) {
        carry += b[j] - '0';
        j--;
      }

      res = char(carry % 2 + '0') + res;
      carry = carry / 2;
    }

    return res;
  }
};