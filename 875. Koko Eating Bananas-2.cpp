class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int left = 1, right = *max_element(piles.begin(), piles.end());
    while (left < right) {
      int mid = (left + right) / 2;
      long long hours = 0;
      for (int p : piles)
        hours += (p + mid - 1) / mid;
      if (hours > h)
        left = mid + 1;
      else
        right = mid;
    }

    return left;
  }
};
