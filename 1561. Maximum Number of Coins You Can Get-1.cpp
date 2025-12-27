class Solution {
public:
  int maxCoins(vector<int> &piles) {
    int n = piles.size() / 3;
    sort(piles.begin(), piles.end());

    int res = 0;
    for (int i = n; i < 3 * n; i += 2)
      res += piles[i];

    return res;
  }
};