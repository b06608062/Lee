class Solution {
public:
  string maxSumOfSquares(int num, int sum) {
    if (num * 9 < sum)
      return "";

    string res = string(sum / 9, '9');
    if (num - sum / 9 > 0)
      res += sum % 9 + '0';
    if (num - res.size() > 0)
      res += string(num - res.size(), '0');

    return res;
  }
};