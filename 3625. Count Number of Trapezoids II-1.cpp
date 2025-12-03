// TLE
class Solution {
public:
  int countTrapezoids(vector<vector<int>> &points) {
    const double INF = DBL_MAX;
    int n = points.size();

    // slope -> (intercept, i, j)
    unordered_map<double, vector<tuple<double, int, int>>> umap;

    for (int i = 0; i < n; ++i) {
      double x1 = points[i][0], y1 = points[i][1];
      for (int j = i + 1; j < n; ++j) {
        double x2 = points[j][0], y2 = points[j][1];
        if (x1 == x2)
          umap[INF].push_back({x1, i, j});
        else if (y1 == y2)
          umap[0].push_back({y1, i, j});
        else {
          double dx = x2 - x1, dy = y2 - y1;
          double m = dy / dx;
          double x0 = x1 - y1 / m;
          umap[m].push_back({x0, i, j});
        }
      }
    }

    set<array<int, 4>> res;

    for (auto &[slope, vec] : umap) {
      int m = vec.size();
      if (m < 2)
        continue;

      for (int i = 0; i < m; ++i) {
        auto &[x0i, pt1, pt2] = vec[i];
        for (int j = i + 1; j < m; ++j) {
          auto &[x0j, pt3, pt4] = vec[j];

          if (x0i == x0j)
            continue;

          set<int> s = {pt1, pt2, pt3, pt4};
          if (s.size() < 4)
            continue;

          array<int, 4> key;
          int k = 0;
          for (int v : s)
            key[k++] = v;

          res.insert(key);
        }
      }
    }

    return res.size();
  }
};
