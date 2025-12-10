class Solution {
public:
  string maxSumOfSquares(int num, int sum) {
    string res = "";
    while (num) {
      int d = min(sum, 9);
      res += d + '0';
      sum -= d;
      num--;
    }

    if (sum && !num)
      return "";

    return res;
  }
};