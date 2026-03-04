struct DSU {
  vector<int> p, sz;
  DSU(int n) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }
  int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
  bool unite(int a, int b) {
    a = find(a), b = find(b);
    if (a == b)
      return false;
    if (sz[a] < sz[b])
      swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
    return true;
  }
};

class Solution {
public:
  void solve(vector<vector<char>> &board) {
    vector<int> dirs{0, 1, 0, -1, 0};
    int m = board.size(), n = board[0].size();
    DSU dsu(m * n + 1);
    int dummy = m * n;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 'X')
          continue;
        if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
          dsu.unite(dummy, i * n + j);
        else {
          for (int d = 0; d < 4; ++d) {
            int nxt_i = i + dirs[d], nxt_j = j + dirs[d + 1];
            if (board[nxt_i][nxt_j] == 'O')
              dsu.unite(i * n + j, nxt_i * n + nxt_j);
          }
        }
      }
    }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (!(dsu.find(i * n + j) == dsu.find(dummy)))
          board[i][j] = 'X';
  }
};
