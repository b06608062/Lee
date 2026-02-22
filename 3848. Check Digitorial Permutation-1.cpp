class Solution {
public:
  bool isDigitorialPermutation(int n) {
    vector<int> f(10);
    f[0] = 1;
    for (int i = 1; i <= 9; ++i)
      f[i] = f[i - 1] * i;

    vector<int> cnt1(10, 0), cnt2(10, 0);
    int sum = 0;
    while (n > 0) {
      sum += f[n % 10];
      cnt1[n % 10]++;
      n /= 10;
    }

    while (sum > 0) {
      cnt2[sum % 10]++;
      sum /= 10;
    }

    return cnt1 == cnt2;
  }
};