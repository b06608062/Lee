class Solution {
public:
  int openLock(vector<string> &deadends, string target) {
    int t = stoi(target);
    int s = 0;
    if (t == s)
      return 0;
    vector<bool> limit(10000, false), vis(10000, false);
    for (auto &d : deadends)
      limit[stoi(d)] = true;
    if (limit[s] || limit[t])
      return -1;
    vector<int> pow_10{1, 10, 100, 1000};

    unordered_set<int> q1, q2;
    vis[s] = true;
    q1.insert(s);
    vis[t] = true;
    q2.insert(t);

    int step = 0;
    while (!q1.empty() && !q2.empty()) {
      ++step;
      if (q1.size() > q2.size())
        swap(q1, q2);
      unordered_set<int> nxt_q;
      for (auto cur : q1) {
        for (int i = 0; i < 4; ++i) {
          int d = (cur / pow_10[i]) % 10;
          for (int j = -1; j <= 1; j += 2) {
            int nxt_d = (d + j + 10) % 10;
            int nxt = cur - d * pow_10[i] + nxt_d * pow_10[i];
            if (q2.count(nxt))
              return step;
            if (vis[nxt] || limit[nxt])
              continue;
            vis[nxt] = true;
            nxt_q.insert(nxt);
          }
        }
      }
      q1.swap(nxt_q);
    }
    return -1;
  }
};