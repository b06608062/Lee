class Solution {
public:
  int minCost(string colors, vector<int> &neededTime) {
    int n = colors.size();

    int r = 0, l = 0, res = 0;
    while (r + 1 < n) {
      while (r + 1 < n && colors[r] == colors[r + 1])
        r++;
      if (r - l >= 1) {
        int pSum =
            accumulate(neededTime.begin() + l, neededTime.begin() + r + 1, 0);
        int pMax =
            *max_element(neededTime.begin() + l, neededTime.begin() + r + 1);
        res += pSum - pMax;
      }
      l = ++r;
    }

    return res;
  }
};