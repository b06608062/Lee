class Solution {
public:
  int maxScore(string s) {
    int n = s.size();
    vector<int> zero(n, 0);

    zero[0] = (s[0] == '0');
    for (int i = 1; i < n; ++i)
      zero[i] = zero[i - 1] + (s[i] == '0');

    int cnt = 0, res = 0;
    for (int i = n - 1; i >= 1; --i) {
      cnt += s[i] == '1';
      res = max(res, zero[i - 1] + cnt);
    }

    return res;
  }
};