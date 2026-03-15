class Solution {
public:
  int myAtoi(string s) {
    int n = s.size();
    int i = 0;
    while (i < n && s[i] == ' ')
      i++;
    int sign = 1;
    if (i < n && (s[i] == '-' || s[i] == '+'))
      sign = s[i++] == '-' ? -1 : 1;

    long long res = 0;
    while (i < n) {
      char d = s[i++] - '0';
      if (0 <= d && d <= 9) {
        res = res * 10 + d;
        long long tmp = res * sign;
        if (tmp < INT_MIN)
          return INT_MIN;
        else if (tmp > INT_MAX)
          return INT_MAX;
      } else
        break;
    }
    res *= sign;
    return res;
  }
};