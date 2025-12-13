// 1827
// 貪心 + 數學
// 先算出 negS，然後從大到小貪心選取數字變成負號
// 最後排序結果即為字典序最小的排列
// 原理：1 ... n - 1 總和為 S = n * (n - 1) / 2，假設 1 ... n - 1 可組成任意 <=
// S 的數字 X
// 則 1 ... n 可組成任意總和為 S + n 之數 Y
// 如果 Y >= n，則 Y - n <= S 可由 1 ... n - 1 組成，加入 n 即可組成 Y
// 如果 Y < n，則 Y 可由 1 ... n - 1 組成
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
