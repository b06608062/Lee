class Solution {
public:
  vector<int> sumAndMultiply(string s, vector<vector<int>> &queries) {
    const int MOD = 1e9 + 7;
    int n = s.size();
    vector<int> pre_sum(n + 1, 0), pre_num(n + 1, 0), pre_non_zero(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      int d = s[i - 1] - '0';
      pre_sum[i] = pre_sum[i - 1] + d;
      pre_num[i] = d ? (pre_num[i - 1] * 10LL + d) % MOD : pre_num[i - 1];
      pre_non_zero[i] = pre_non_zero[i - 1] + (d ? 1 : 0);
    }

    const int MAX_N = 100001;
    vector<int> pow10(MAX_N, 1);
    for (int i = 1; i < MAX_N; ++i)
      pow10[i] = (pow10[i - 1] * 10LL) % MOD;

    vector<int> res;
    for (auto &q : queries) {
      int l = q[0], r = q[1] + 1;
      int len = pre_non_zero[r] - pre_non_zero[l];
      long long x = pre_num[r] - (1LL * pre_num[l] * pow10[len] % MOD) + MOD;
      res.push_back(x * (pre_sum[r] - pre_sum[l]) % MOD);
    }

    return res;
  }
};