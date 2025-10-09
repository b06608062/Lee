class Solution {
public:
  int openLock(vector<string> &deadends, string target) {
    unordered_set<string> dead(deadends.begin(), deadends.end());
    string start = "0000";

    if (dead.count(start) || dead.count(target))
      return -1;

    if (target == start)
      return 0;

    unordered_set<string> q1{start}, q2{target};
    unordered_set<string> seen{start, target};

    int step = 0;
    while (!q1.empty() && !q2.empty()) {
      step++;
      if (q1.size() > q2.size())
        swap(q1, q2);
      unordered_set<string> nq;
      for (auto &cur : q1) {
        for (int i = 0; i < 4; ++i) {
          for (int j = -1; j <= 1; j += 2) {
            string nxt = cur;
            nxt[i] = (nxt[i] - '0' + j + 10) % 10 + '0';
            if (q2.count(nxt))
              return step;
            if (dead.count(nxt) || seen.count(nxt))
              continue;
            seen.insert(nxt);
            nq.insert(nxt);
          }
        }
      }
      q1.swap(nq);
    }

    return -1;
  }
};
