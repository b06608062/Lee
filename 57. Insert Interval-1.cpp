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

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    int n = intervals.size();

    vector<vector<int>> res;
    int i = 0;
    while (i < n && intervals[i][1] < newInterval[0])
      res.push_back(intervals[i++]);

    while (i < n && intervals[i][0] <= newInterval[1]) {
      newInterval[0] = min(newInterval[0], intervals[i][0]);
      newInterval[1] = max(newInterval[1], intervals[i][1]);
      i++;
    }

    res.push_back(newInterval);

    while (i < n)
      res.push_back(intervals[i++]);

    return res;
  }
};