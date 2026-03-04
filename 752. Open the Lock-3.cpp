class Solution {
public:
  int openLock(vector<string> &deadends, string target) {
    int t = stoi(target);
    int start = 0;
    if (t == start)
      return 0;
    vector<bool> limit(10000, false), vis(10000, false);
    for (auto &d : deadends)
      limit[stoi(d)] = true;
    if (limit[start] || limit[t])
      return -1;
    vector<int> pow_10{1, 10, 100, 1000};
    queue<int> q;
    vis[0] = true;
    q.push(0);

    int step = 0;
    while (!q.empty()) {
      ++step;
      int sz = q.size();
      while (sz--) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
          int d = (cur / pow_10[i]) % 10;
          for (int j = -1; j <= 1; j += 2) {
            int nxt_d = (d + j + 10) % 10;
            int nxt = cur - d * pow_10[i] + nxt_d * pow_10[i];
            if (vis[nxt] || limit[nxt])
              continue;
            if (nxt == t)
              return step;
            vis[nxt] = true;
            q.push(nxt);
          }
        }
      }
    }

    return -1;
  }
};