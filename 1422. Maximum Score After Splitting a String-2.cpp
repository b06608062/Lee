// score = zero + (totalOne - one)
class Solution {
public:
  int maxScore(string s) {
    int n = s.size();

    int zero = 0, one = 0, res = INT_MIN / 2;
    for (int i = 0; i < n - 1; ++i) {
      if (s[i] == '1')
        one++;
      else
        zero++;
      res = max(res, zero - one);
    }

    if (s[n - 1] == '1')
      one++;

    return res + one;
  }
};