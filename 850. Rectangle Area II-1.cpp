// mark
// 2236
// 2D 差分陣列 + 值域離散化
// 離散化後的索引 i 並不代表一個「點」，而是代表一個「區間」
class Solution {
public:
  int rectangleArea(vector<vector<int>> &rectangles) {
    const int MOD = 1e9 + 7;

    set<int> x_set, y_set;
    for (auto &r : rectangles) {
      x_set.insert(r[0]);
      x_set.insert(r[2]);
      y_set.insert(r[1]);
      y_set.insert(r[3]);
    }
    vector<int> xs(x_set.begin(), x_set.end());
    vector<int> ys(y_set.begin(), y_set.end());

    int nx = xs.size(), ny = ys.size();
    vector<vector<int>> diff(nx, vector<int>(ny, 0));

    auto get_idx = [](vector<int> &vec, int val) {
      return lower_bound(vec.begin(), vec.end(), val) - vec.begin();
    };

    for (auto &r : rectangles) {
      int i1 = get_idx(xs, r[0]), i2 = get_idx(xs, r[2]);
      int j1 = get_idx(ys, r[1]), j2 = get_idx(ys, r[3]);
      diff[i1][j1]++;
      diff[i1][j2]--;
      diff[i2][j1]--;
      diff[i2][j2]++;
    }

    long long res = 0;

    vector<vector<int>> f(nx, vector<int>(ny, 0));
    for (int i = 0; i < nx; ++i) {
      for (int j = 0; j < ny; ++j) {
        // f(i,j) = diff(i,j) + f(i-1,j) + f(i,j-1) - f(i-1,j-1)
        f[i][j] = diff[i][j];
        if (i > 0)
          f[i][j] += f[i - 1][j];
        if (j > 0)
          f[i][j] += f[i][j - 1];
        if (i > 0 && j > 0)
          f[i][j] -= f[i - 1][j - 1];
        if (f[i][j] > 0) {
          long long width = xs[i + 1] - xs[i];
          long long height = ys[j + 1] - ys[j];
          res = (res + width * height) % MOD;
        }
      }
    }

    return res;
  }
};

class Solution {
public:
  int rectangleArea(vector<vector<int>> &rectangles) {
    const int MOD = 1e9 + 7;

    set<int> x_set, y_set;
    for (auto &r : rectangles) {
      x_set.insert(r[0]);
      x_set.insert(r[2]);
      y_set.insert(r[1]);
      y_set.insert(r[3]);
    }
    vector<int> xs(x_set.begin(), x_set.end());
    vector<int> ys(y_set.begin(), y_set.end());

    int nx = xs.size(), ny = ys.size();
    vector<vector<int>> diff(nx, vector<int>(ny, 0));

    unordered_map<int, int> x_map, y_map;
    for (int i = 0; i < xs.size(); ++i)
      x_map[xs[i]] = i;
    for (int j = 0; j < ys.size(); ++j)
      y_map[ys[j]] = j;

    for (auto &r : rectangles) {
      int i1 = x_map[r[0]], i2 = x_map[r[2]];
      int j1 = y_map[r[1]], j2 = y_map[r[3]];
      diff[i1][j1]++;
      diff[i1][j2]--;
      diff[i2][j1]--;
      diff[i2][j2]++;
    }

    long long res = 0;

    vector<vector<int>> f(nx, vector<int>(ny, 0));
    for (int i = 0; i < nx; ++i) {
      for (int j = 0; j < ny; ++j) {
        // f(i,j) = diff(i,j) + f(i-1,j) + f(i,j-1) - f(i-1,j-1)
        f[i][j] = diff[i][j];
        if (i > 0)
          f[i][j] += f[i - 1][j];
        if (j > 0)
          f[i][j] += f[i][j - 1];
        if (i > 0 && j > 0)
          f[i][j] -= f[i - 1][j - 1];
        if (f[i][j] > 0) {
          long long width = xs[i + 1] - xs[i];
          long long height = ys[j + 1] - ys[j];
          res = (res + width * height) % MOD;
        }
      }
    }

    return res;
  }
};
