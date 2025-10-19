class Solution {
public:
  string findLexSmallestString(string s, int a, int b) {
    int n = s.size();

    set<string> sset{s};
    queue<string> q;

    q.push(s);
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      auto nxt1 = cur;
      for (int i = 1; i < n; i += 2) {
        char &ch = nxt1[i];
        ch = (ch - '0' + a) % 10 + '0';
      }
      if (!sset.count(nxt1)) {
        sset.insert(nxt1);
        q.push(nxt1);
      }
      auto nxt2 = cur;
      reverse(nxt2.begin(), nxt2.end());
      reverse(nxt2.begin(), nxt2.begin() + b);
      reverse(nxt2.begin() + b, nxt2.end());
      if (!sset.count(nxt2)) {
        sset.insert(nxt2);
        q.push(nxt2);
      }
    }

    return *sset.begin();
  }
};