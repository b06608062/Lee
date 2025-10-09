class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](auto &a, auto &b) { return a[1] < b[1]; });

    int curEnd = intervals[0][1], res = 0;
    for (int i = 1; i < intervals.size(); ++i)
      if (intervals[i][0] >= curEnd)
        curEnd = intervals[i][1];
      else
        res++;

    return res;
  }
};