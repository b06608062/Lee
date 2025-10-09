class Solution {
public:
  vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                              long long success) {
    int n = spells.size(), m = potions.size();

    sort(potions.begin(), potions.end());

    vector<int> res(n, 0);
    for (int i = 0; i < n; ++i) {
      long long x = spells[i];
      int left = 0, right = m;
      while (left < right) {
        int mid = left + (right - left) / 2;
        long long prod = x * potions[mid];
        if (prod < success)
          left = mid + 1;
        else
          right = mid;
      }
      res[i] = m - left;
    }

    return res;
  }
};