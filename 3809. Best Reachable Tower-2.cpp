class Solution {
public:
  vector<int> bestTower(vector<vector<int>> &towers, vector<int> &center,
                        int radius) {
    int cx = center[0], cy = center[1], r = radius;

    tuple<int, int, int> best = {1, -1, -1};

    for (auto &t : towers) {
      int x = t[0], y = t[1], q = t[2];
      if (abs(x - cx) + abs(y - cy) <= r) {
        best = min(best, {-q, x, y});
      }
    }

    if (get<0>(best) > 0)
      return {-1, -1};

    return {get<1>(best), get<2>(best)};
  }
};