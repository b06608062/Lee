class Solution {
public:
  double largestTriangleArea(vector<vector<int>> &points) {
    int n = points.size();

    auto helper = [](auto &A, auto &B, auto &C) {
      long long x1 = B[0] - A[0], y1 = B[1] - A[1];
      long long x2 = C[0] - A[0], y2 = C[1] - A[1];
      long long cross = x1 * y2 - y1 * x2;
      return abs((double)cross) * 0.5; // Area = |(B - A) × (C - A)| / 2
    };

    double res = 0.0;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        for (int k = j + 1; k < n; ++k)
          res = max(res, helper(points[i], points[j], points[k]));

    return res;
  }
};
