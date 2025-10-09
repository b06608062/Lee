struct Element {
  string s;
  int open, close;
};

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    queue<Element> q;

    vector<string> res;
    q.push({"", 0, 0});
    while (!q.empty()) {
      auto &cur = q.front();
      q.pop();

      if (cur.s.size() == 2 * n) {
        res.push_back(std::move(cur.s));
        continue;
      }

      if (cur.open < n)
        q.push({cur.s + "(", cur.open + 1, cur.close});

      if (cur.close < cur.open)
        q.push({cur.s + ")", cur.open, cur.close + 1});
    }

    return res;
  }
};
