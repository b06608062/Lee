class Solution {
public:
  int maximizeWin(vector<int> &prizePositions, int k) {
    int n = prizePositions.size();

    vector<int> covered(n);

    int cnt = 0;
    for (int i = 0, j = 0; i < n; ++i) {
      while (j < n && prizePositions[j] - prizePositions[i] <= k)
        j++, cnt++;
      covered[i] = cnt--;
    }

    int maxR = 0, res = 0;
    for (int i = n - 1, j = n - 1; i >= 0; --i) {
      while (prizePositions[j] - prizePositions[i] > k)
        maxR = max(maxR, covered[j--]);
      res = max(res, covered[i] + maxR);
    }

    return res;
  }
};