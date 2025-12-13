// mark
// 1968
// Multi-Prefix + Rolling Number + 區間拼數查詢
class Solution {
public:
  vector<int> sumAndMultiply(string s, vector<vector<int>> &queries) {
    const int MOD = 1e9 + 7;
    int n = s.size();

    vector<long long> px(n + 1, 0), ps(n + 1, 0), pnz(n + 1, 0),
        pow10(n + 1, 1);

    long long x = 0, sum = 0, nz = 0;
    for (int i = 1; i <= n; ++i) {
      int d = s[i - 1] - '0';
      if (d) {
        x = (x * 10 + d) % MOD;
        sum = (sum + d) % MOD;
        nz++;
      }
      px[i] = x;
      ps[i] = sum;
      pnz[i] = nz;
      pow10[i] = pow10[i - 1] * 10 % MOD;
    }

    vector<int> res;
    for (auto &q : queries) {
      int l = q[0], r = q[1];
      int m = pnz[r + 1] - pnz[l];
      long long sum = ps[r + 1] - ps[l];
      long long x = (px[r + 1] - px[l] * pow10[m]) % MOD;
      res.push_back((x * sum % MOD + MOD) % MOD);
    }

    return res;
  }
};