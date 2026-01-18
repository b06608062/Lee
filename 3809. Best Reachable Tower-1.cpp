class Solution {
public:
  vector<int> bestTower(vector<vector<int>> &towers, vector<int> &center,
                        int radius) {
    const int INF = INT_MIN / 2;
    int cx = center[0], cy = center[1], r = radius;
    int mx = INF;
    pair<int, int> cur = {-1, -1};
    for (auto &t : towers) {
      int x = t[0], y = t[1], q = t[2];
      if (abs(x - cx) + abs(y - cy) <= r) {
        if (q >= mx) {
          if (q > mx) {
            mx = q;
            cur = {x, y};
          } else {
            cur = min(cur, {x, y});
          }
        }
      }
    }

    return {cur.first, cur.second};
  }
};