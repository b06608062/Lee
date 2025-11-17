class Solution {
public:
  const int MOD = 1e9 + 7;
  int numSub(string s) {
    int n = s.size();

    int last0 = -1, res = 0;
    for (int i = 0; i < n; ++i)
      if (s[i] == '1') {
        res += i - last0;
        res %= MOD;
      } else
        last0 = i;

    return res;
  }
};