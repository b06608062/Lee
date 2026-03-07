// mark
// 2006
// 字串環狀結構 (s + s) + 滑窗

class Solution {
public:
  int minFlips(string s) {
    int n = s.size();
    string ss = s + s;
    int r = 0, cnt = 0, res = n;
    while (r < 2 * n) {
      cnt += (r % 2) ^ (ss[r] - '0');
      if (r >= n)
        cnt -= ((r - n) % 2) ^ (ss[r - n] - '0');
      if (r >= n - 1)
        res = min({res, cnt, n - cnt});
      r++;
    }

    return res;
  }
};