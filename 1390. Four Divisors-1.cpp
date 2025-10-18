class Solution {
public:
  int sumFourDivisors(vector<int> &nums) {
    int res = 0;
    for (auto x : nums) {
      int cnt = 0, sum = 0;
      for (int i = 1; i * i <= x; ++i)
        if (x % i == 0) {
          sum += i;
          sum += x / i;
          cnt += 2;
          if (i * i == x) {
            sum -= i;
            cnt -= 1;
          }
          if (cnt > 4)
            break;
        }
      if (cnt == 4)
        res += sum;
    }

    return res;
  }
};