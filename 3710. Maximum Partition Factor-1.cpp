class Solution {
public:
  int maxPartitionFactor(vector<vector<int>> &points) {
    int n = points.size();
    if (n <= 2)
      return 0;

    auto eval = [](auto &a, auto &b) -> int {
      return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    };

    int maxD = INT_MIN;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        maxD = max(maxD, eval(points[i], points[j]));

    auto check = [&](int D) -> bool {
      vector<int> colors(n, 0);

      auto dfs = [&](this auto &&dfs, int u, int c) -> bool {
        colors[u] = c;
        for (int v = 0; v < n; ++v)
          if (v != u && eval(points[u], points[v]) < D)
            if (colors[v] == c || (colors[v] == 0 && !dfs(v, -c)))
              return false;
        return true;
      };

      for (int i = 0; i < n; ++i)
        if (!colors[i] && !dfs(i, 1))
          return false;

      return true;
    };

    int lo = 1, hi = maxD + 1;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (check(mid))
        lo = mid + 1;
      else
        hi = mid;
    }

    return lo - 1;
  }
};