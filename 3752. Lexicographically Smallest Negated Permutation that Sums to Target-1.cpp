class Solution {
public:
  vector<int> lexSmallestNegatedPerm(int n, long long target) {
    long long S = 1LL * n * (n + 1) / 2;

    if (target > S || target < -S)
      return {};
    // posS + negS = S
    // posS - negS = target
    // negS = (S - target) / 2
    long long X = S - target;
    if (X % 2 != 0)
      return {};
    X /= 2;

    vector<int> sign(n + 1, 1);

    for (int x = n; x >= 1; --x) {
      if (x <= X) {
        sign[x] = -1;
        X -= x;
      }
    }

    vector<int> res;
    for (int i = 1; i <= n; ++i)
      res.push_back(sign[i] * i);

    sort(res.begin(), res.end());
    return res;
  }
};
