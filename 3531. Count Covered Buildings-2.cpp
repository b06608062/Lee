// mark
// 1519
// 紀錄行列最大最小值
// O(m + n)
class Solution {
public:
  int countCoveredBuildings(int n, vector<vector<int>> &buildings) {
    const int INF = n + 1;

    vector<int> rowMin(n + 1, INF), rowMax(n + 1, 0);
    vector<int> colMin(n + 1, INF), colMax(n + 1, 0);

    for (auto &b : buildings) {
      int r = b[0], c = b[1];
      rowMin[r] = min(rowMin[r], c);
      rowMax[r] = max(rowMax[r], c);
      colMin[c] = min(colMin[c], r);
      colMax[c] = max(colMax[c], r);
    }

    int res = 0;
    for (auto &b : buildings) {
      int r = b[0], c = b[1];
      if (rowMin[r] < c && c < rowMax[r] && colMin[c] < r && r < colMax[c])
        res++;
    }

    return res;
  }
};
