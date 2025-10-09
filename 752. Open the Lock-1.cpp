class Solution {
public:
  int openLock(vector<string> &deadends, string target) {
    unordered_set<string> dead(deadends.begin(), deadends.end());
    string start = "0000";

    if (dead.count(start) || dead.count(target))
      return -1;

    if (target == start)
      return 0;

    unordered_set<string> seen;
    queue<string> q;

    seen.insert(start);
    q.push(start);
    int step = 0;
    while (!q.empty()) {
      step++;
      int size = q.size();
      while (size--) {
        string &cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
          for (int j = -1; j <= 1; j += 2) {
            string nxt = cur;
            nxt[i] = (nxt[i] - '0' + j + 10) % 10 + '0';
            if (nxt == target)
              return step;
            if (dead.count(nxt) || seen.count(nxt))
              continue;
            seen.insert(nxt);
            q.push(nxt);
          }
        }
      }
    }

    return -1;
  }
};