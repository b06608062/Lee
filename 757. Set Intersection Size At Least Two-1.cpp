class Solution {
public:
  int intersectionSizeTwo(vector<vector<int>> &intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
      if (a[1] != b[1])
        return a[1] < b[1];
      return a[1] - a[0] < b[1] - b[0];
    });

    int a = intervals[0][1], b = intervals[0][1] - 1;
    int res = 2;
    for (int i = 1; i < n; ++i) {
      int starti = intervals[i][0], endi = intervals[i][1];
      if (starti <= b)
        continue;
      else if (starti <= a) {
        b = a;
        a = endi;
        res++;
      } else {
        a = endi;
        b = a - 1;
        res += 2;
      }
    }

    return res;
  }
};