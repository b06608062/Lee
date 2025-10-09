class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    int n = intervals.size();

    vector<vector<int>> res;
    int newStart = newInterval[0], newEnd = newInterval[1];
    int i = 0;
    for (; i < n; ++i)
      if (intervals[i][1] >= newStart)
        break;
      else
        res.push_back(intervals[i]);

    if (i < n)
      newStart = min(newStart, intervals[i][0]);

    for (; i < n; ++i)
      if (intervals[i][0] > newEnd)
        break;
      else
        newEnd = max(newEnd, intervals[i][1]);

    res.push_back({newStart, newEnd});

    for (; i < n; ++i)
      res.push_back(intervals[i]);

    return res;
  }
};