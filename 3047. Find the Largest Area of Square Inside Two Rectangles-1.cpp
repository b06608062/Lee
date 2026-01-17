class Solution {
public:
  long long largestSquareArea(vector<vector<int>> &bottomLeft,
                              vector<vector<int>> &topRight) {
    int n = bottomLeft.size();
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      int a1 = bottomLeft[i][0];
      int b1 = bottomLeft[i][1];
      int c1 = topRight[i][0];
      int d1 = topRight[i][1];
      for (int j = i + 1; j < n; ++j) {
        int a2 = bottomLeft[j][0];
        int b2 = bottomLeft[j][1];
        int c2 = topRight[j][0];
        int d2 = topRight[j][1];
        if (a1 < c2 && a2 < c1 && b1 < d2 && b2 < d1) {
          int w = min(c1, c2) - max(a1, a2);
          int h = min(d1, d2) - max(b1, b2);
          mx = max(mx, min(w, h));
        }
      }
    }

    return 1ll * mx * mx;
  }
};