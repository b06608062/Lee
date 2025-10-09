class Solution {
public:
  bool isThree(int n) {
    int res = 0;
    for (int i = 1; i <= sqrt(n); ++i)
      if (n % i == 0) {
        if (i * i == n)
          res += 1;
        else
          res += 2;
      }

    return res == 3;
  }
};