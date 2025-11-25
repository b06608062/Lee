class Solution {
public:
  int shipWithinDays(vector<int> &weights, int days) {
    int l = *max_element(weights.begin(), weights.end()),
        r = accumulate(weights.begin(), weights.end(), 0);
    while (l < r) {
      int m = l + (r - l) / 2;
      int day = 1, cap = m;
      for (auto w : weights)
        if (w <= cap)
          cap -= w;
        else {
          cap = m - w;
          day++;
        }

      if (day > days)
        l = m + 1;
      else
        r = m;
    }

    return l;
  }
};