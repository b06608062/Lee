class Solution {
public:
  string longestDiverseString(int a, int b, int c) {
    using P = pair<int, int>; // f, ch
    priority_queue<P> pq;

    if (a > 0)
      pq.push({a, 'a'});
    if (b > 0)
      pq.push({b, 'b'});
    if (c > 0)
      pq.push({c, 'c'});

    string res = "";
    while (!pq.empty()) {
      if (pq.size() == 1) {
        auto [f, ch] = pq.top();
        pq.pop();
        res += ch;
        if (f > 1)
          res += ch;
        return res;
      }

      auto [f1, ch1] = pq.top();
      pq.pop();
      auto [f2, ch2] = pq.top();
      pq.pop();
      int k = f1 == f2 ? 1 : 2;
      for (int i = 0; i < k; ++i)
        res += ch1;
      res += ch2;

      f1 -= k;
      f2 -= 1;
      if (f1)
        pq.push({f1, ch1});
      if (f2)
        pq.push({f2, ch2});
    }

    return res;
  }
};