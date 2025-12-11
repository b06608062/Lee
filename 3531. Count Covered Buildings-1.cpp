class Solution {
public:
  int countCoveredBuildings(int n, vector<vector<int>> &buildings) {
    unordered_map<int, vector<int>> rows, cols;
    for (auto &b : buildings) {
      int r = b[0], c = b[1];
      rows[r].push_back(c);
      cols[c].push_back(r);
    }

    for (auto &[_, row] : rows)
      sort(row.begin(), row.end());
    for (auto &[_, col] : cols)
      sort(col.begin(), col.end());

    int res = 0;
    for (auto &b : buildings) {
      int r = b[0], c = b[1];
      auto &row = rows[r];
      auto it = lower_bound(row.begin(), row.end(), c);
      if (it == row.begin() || it == row.end() - 1)
        continue;
      auto &col = cols[c];
      it = lower_bound(col.begin(), col.end(), r);
      if (it != col.begin() && it != col.end() - 1)
        res++;
    }

    return res;
  }
};