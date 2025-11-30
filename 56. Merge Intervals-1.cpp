class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](auto &a, auto &b) { return a[0] < b[0]; });

    vector<vector<int>> res;
    res.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i)
      if (intervals[i][0] <= res.back()[1])
        res.back()[1] = max(res.back()[1], intervals[i][1]);
      else
        res.push_back(intervals[i]);

    return res;
  }
};

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(),
         [](auto &a, auto &b) { return a[0] < b[0]; });

    vector<vector<int>> res;
    for (int i = 0; i < n; ++i)
      if (res.empty() || intervals[i][0] > res.back()[1])
        res.push_back(intervals[i]);
      else
        res.back()[1] = max(res.back()[1], intervals[i][1]);

    return res;
  }
};