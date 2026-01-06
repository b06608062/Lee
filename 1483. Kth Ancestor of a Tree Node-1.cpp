// mark
// 數上倍增法
class TreeAncestor {
  vector<vector<int>> up;
  int maxLog;

public:
  TreeAncestor(int n, vector<int> &parent) {
    // 50000 稍微小於 2^16，所以 16 或 17 夠用了
    maxLog = 16;
    up.assign(n, vector<int>(maxLog + 1, -1));

    // 初始化：第 2^0 (即第 1 個) 祖先就是 parent
    for (int i = 0; i < n; ++i)
      up[i][0] = parent[i];

    // 動態規劃預處理所有 2^j 祖先
    for (int j = 1; j <= maxLog; ++j)
      for (int i = 0; i < n; ++i)
        if (up[i][j - 1] != -1)
          // 第 2^j 個祖先 = (第 2^j-1 個祖先) 的 (第 2^j-1 個祖先)
          up[i][j] = up[up[i][j - 1]][j - 1];
  }

  int getKthAncestor(int node, int k) {
    for (int j = 0; j <= maxLog; ++j) {
      // 檢查 k 的二進制位元，如果第 j 位是 1，就往上跳 2^j 步
      if ((k >> j) & 1) {
        node = up[node][j];
        if (node == -1)
          break; // 如果已經跳出樹根了
      }
    }
    return node;
  }
};