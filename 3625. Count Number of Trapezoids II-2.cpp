// mark
// 2643
// 平行四邊形計數
class Solution {
public:
  int countTrapezoids(vector<vector<int>> &points) {
    const double INF = DBL_MAX;
    int n = points.size();
    unordered_map<double, unordered_map<double, int>>
        umap; // slpoe -> (itc -> cnt)
    map<pair<int, int>, unordered_map<double, int>>
        mmap; // middle -> (slpoe -> cnt);
    for (int i = 0; i < n; ++i) {
      int x1 = points[i][0], y1 = points[i][1];
      for (int j = i + 1; j < n; ++j) {
        int x2 = points[j][0], y2 = points[j][1];
        double m, itc;
        if (x1 == x2) {
          m = INF;
          itc = x1;
        } else if (y1 == y2) {
          m = 0;
          itc = y1;
        } else {
          double dx = x2 - x1;
          double dy = y2 - y1;
          m = dy / dx;
          itc = (y1 * dx - x1 * dy) / dx;
        }
        umap[m][itc]++;
        mmap[{x1 + x2, y1 + y2}][m]++;
      }
    }

    int res = 0;
    for (auto &[_, itc] : umap) {
      int prev = 0;
      for (auto &[_, cnt] : itc) {
        res += prev * cnt;
        prev += cnt;
      }
    }

    for (auto &[_, slp] : mmap) {
      int prev = 0;
      for (auto &[_, cnt] : slp) {
        res -= prev * cnt;
        prev += cnt;
      }
    }

    return res;
  }
};