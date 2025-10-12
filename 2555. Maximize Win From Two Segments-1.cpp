class Solution {
public:
  int maximizeWin(vector<int> &prizePositions, int k) {
    int n = prizePositions.size();

    vector<int> pref(n + 1, 0);

    int i = 0, res = 0;
    for (int j = 0; j < n; ++j) {
      while (prizePositions[j] - prizePositions[i] > k)
        i++;
      res = max(res, (j - i + 1) + pref[i]);
      pref[j + 1] = max(pref[j], j - i + 1);
    }

    return res;
  }
};