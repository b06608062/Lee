class Solution {
public:
  int minTimeToVisitAllPoints(vector<vector<int>> &points) {
    int n = points.size();

    int res = 0;
    for (int i = 1; i < n; ++i) {
      int x0 = points[i - 1][0], y0 = points[i - 1][1];
      int x1 = points[i][0], y1 = points[i][1];
      res += max(abs(x1 - x0), abs(y1 - y0));
    }

    return res;
  }
};