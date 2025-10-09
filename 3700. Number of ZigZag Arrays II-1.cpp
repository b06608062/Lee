class Solution {
public:
  static constexpr int MOD = 1'000'000'007;
  using Mat = vector<vector<int>>;

  Mat mul(const Mat &A, const Mat &B) {
    int n = A.size();

    Mat C(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
      for (int k = 0; k < n; ++k)
        if (A[i][k]) {
          long long aik = A[i][k];
          for (int j = 0; j < n; ++j)
            if (B[k][j])
              C[i][j] = (C[i][j] + aik * B[k][j]) % MOD;
        }

    return C;
  }

  Mat powMul(Mat base, int e) {
    int n = base.size();

    Mat res(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
      res[i][i] = 1;

    while (e > 0) {
      if (e & 1)
        res = mul(base, res);
      base = mul(base, base);
      e >>= 1;
    }

    return res;
  }

  int zigZagArrays(int n, int l, int r) {
    int k = r - l + 1;

    vector<int> f(k, 1); // f1 = [1,1,...,1]

    Mat T(k, vector<int>(k, 0));
    for (int i = 0; i < k; ++i)
      for (int j = 0; j < k; ++j)
        if (i + j < k - 1)
          T[i][j] = 1;

    // fn = T^(n-1) * f1
    Mat P = powMul(T, n - 1);

    long long sumFn = 0;
    for (int i = 0; i < k; ++i) {
      long long val = 0;
      for (int j = 0; j < k; ++j)
        if (P[i][j])
          val = (val + 1LL * P[i][j] * f[j]) % MOD;
      sumFn += val;
      if (sumFn >= MOD)
        sumFn -= MOD;
    }

    return int((sumFn * 2) % MOD);
  }
};
