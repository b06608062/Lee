// mark
// 1735
// 浮點數二分搜 + 預處理加速
struct Square {
  double y, l, area;
};

class Solution {
public:
  vector<Square> data;
  double A;
  double separateSquares(vector<vector<int>> &squares) {
    A = 0;
    double mn = DBL_MAX, mx = 0;
    int n = squares.size();
    data.resize(n);
    for (int i = 0; i < n; ++i) {
      data[i].y = squares[i][1];
      data[i].l = squares[i][2];
      data[i].area = data[i].l * data[i].l;
      A += data[i].area;
      mn = min(mn, data[i].y);
      mx = max(mx, data[i].y + data[i].l);
    }

    double lo = mn, hi = mx;
    for (int i = 0; i < 50; ++i) {
      double mid = lo + (hi - lo) / 2.0;
      if (helper(data, mid))
        lo = mid;
      else
        hi = mid;
    }

    return lo;
  }

private:
  bool helper(vector<Square> &data, double mid) {
    double area = 0;
    for (auto &s : data) {
      if (mid <= s.y)
        continue;
      if (mid >= s.y + s.l)
        area += s.area;
      else
        area += s.l * (mid - s.y);
    }

    return area < A / 2;
  }
};