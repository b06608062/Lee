class Solution {
public:
  int reverse(int x) {
    int res = 0;
    while (x != 0) {
      int digit = x % 10;
      if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > INT_MAX % 10))
        return 0; // Overflow if res is going to be greater than INT_MAX
      if (res < INT_MIN / 10 || (res == INT_MIN / 10 && digit < INT_MIN % 10))
        return 0; // Underflow if res is going to be less than INT_MIN
      res = res * 10 + digit;
      x /= 10;
    }

    return res;
  }
};