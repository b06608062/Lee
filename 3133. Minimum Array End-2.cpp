class Solution {
public:
  long long minEnd(int n, int x) {
    bitset<64> X(x), N(n - 1), result(0);

    for (int i = 0, j = 0; i < 64; ++i)
      result[i] = X[i] ? 1 : N[j++];

    return result.to_ullong();
  }
};