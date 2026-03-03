class Solution {
public:
  string longestDiverseString(int a, int b, int c) {
    priority_queue<pair<int, char>> pq;
    if (a)
      pq.push({a, 'a'});
    if (b)
      pq.push({b, 'b'});
    if (c)
      pq.push({c, 'c'});
    string res = "";
    while (!pq.empty()) {
      auto [f1, ch1] = pq.top();
      pq.pop();
      int n = res.size();
      if (n >= 2 && res[n - 1] == ch1 && res[n - 2] == ch1) {
        if (pq.empty())
          break;
        auto [f2, ch2] = pq.top();
        pq.pop();
        res += ch2;
        if (--f2)
          pq.push({f2, ch2});
        res += ch1;
        if (--f1)
          pq.push({f1, ch1});
      } else {
        res += ch1;
        if (--f1)
          pq.push({f1, ch1});
      }
    }
    return res;
  }
};