class Solution {
public:
  string maxSumOfSquares(int num, int sum) {
    if (num * 9 < sum)
      return "";

    string res = "";
    while (num) {
      if (sum >= 9)
        res += '9';
      else if (sum > 0)
        res += char(sum % 9 + '0');
      else
        res += '0';
      sum -= 9;
      num--;
    }

    return res;
  }
};