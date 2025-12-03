// mark
// 2020
// 迷宮跳躍 BFS
class Solution {
public:
  int snakesAndLadders(vector<vector<int>> &board) {
    int n = board.size();

    vector<bool> vis(n * n + 1, false);
    queue<int> q;

    vis[1] = true;
    q.push(1);
    int step = 0;
    while (!q.empty()) {
      step++;
      int sz = q.size();
      while (sz--) {
        int i = q.front();
        q.pop();
        for (int j = i + 1; j <= min(i + 6, n * n); ++j) {
          int rj = (n - 1) - ((j - 1) / n);
          int cj =
              (rj % 2) == ((n - 1) % 2) ? (j - 1) % n : (n - 1) - ((j - 1) % n);
          int nj = j;
          if (board[rj][cj] > 0)
            nj = board[rj][cj];
          if (nj == n * n)
            return step;
          if (vis[nj])
            continue;
          vis[nj] = true;
          q.push(nj);
        }
      }
    }

    return -1;
  }
};