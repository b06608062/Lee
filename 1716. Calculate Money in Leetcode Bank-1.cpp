class Solution {
public:
  int totalMoney(int n) {
    int base = 0;
    for (int i = 1; i <= 7; ++i)
      base += i;

    int weeks = n / 7;

    int remain = 0;
    if (n % 7) {
      for (int i = 1; i <= n % 7; ++i)
        remain += i + weeks;
    }

    return base * weeks + 7 * (weeks - 1) * weeks / 2 + remain;
  }
};