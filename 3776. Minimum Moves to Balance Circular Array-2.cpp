// mark
// 1740
// Greedy 模擬 + 雙指標左右環狀擴展
class Solution {
public:
  long long minMoves(vector<int> &balance) {
    int n = balance.size();

    long long sum = 0;
    int negIdx = -1;
    for (int i = 0; i < n; ++i) {
      sum += balance[i];
      if (balance[i] < 0)
        negIdx = i;
    }

    if (sum < 0)
      return -1;
    if (negIdx == -1)
      return 0;

    int need = -balance[negIdx];
    long long res = 0;
    for (int d = 1; d <= n && need > 0; ++d) {
      int l = (negIdx - d + n) % n;
      int r = (negIdx + d) % n;

      int used = min(balance[l], need);
      need -= used;
      res += 1ll * used * d;

      if (need > 0) {
        used = min(balance[r], need);
        need -= used;
        res += 1ll * used * d;
      }
    }

    return res;
  }
};
