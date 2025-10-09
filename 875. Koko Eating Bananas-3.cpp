class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int left = 0, right = *max_element(piles.begin(), piles.end());
    while (right - left > 1) {
      int mid = (left + right) / 2;
      long long hours = 0;
      for (int p : piles)
        hours += (p + mid - 1) / mid;
      if (hours > h)
        left = mid;
      else
        right = mid;
    }

    return right;
  }
};
