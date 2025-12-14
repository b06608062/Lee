// mark
// Fenwick Tree
struct FenwickTree {
  vector<int> bit;
  FenwickTree(int n) : bit(n + 1, 0) {}

  void update(int i, int delta) {
    while (i < bit.size()) {
      bit[i] += delta;
      i += lowbit(i);
    }
  }

  int query(int i) {
    int sum = 0;
    while (i > 0) {
      sum += bit[i];
      i -= lowbit(i);
    }
    return sum;
  }

  int lowbit(int x) { return x & (-x); }
};

class Solution {
public:
  vector<int> minDeletions(string s, vector<vector<int>> &queries) {
    int n = s.size();
    vector<int> res;
    if (n == 1) {
      for (auto &q : queries)
        if (q[0] == 2)
          res.push_back(0);
      return res;
    }

    FenwickTree ft(n);
    for (int i = 1; i < n; ++i)
      if (s[i] == s[i - 1])
        ft.update(i + 1, 1);

    for (auto &q : queries) {
      if (q[0] == 1) {
        int j = q[1];
        if (j == 0) {
          ft.update(j + 2, s[j] == s[j + 1] ? -1 : 1);
        } else if (j == n - 1) {
          ft.update(j + 1, s[j] == s[j - 1] ? -1 : 1);
        } else {
          if (s[j - 1] == s[j] && s[j] == s[j + 1]) {
            // aaa
            ft.update(j + 1, -1);
            ft.update(j + 2, -1);
          } else if (s[j - 1] == s[j] && s[j] != s[j + 1]) {
            // aab
            ft.update(j + 1, -1);
            ft.update(j + 2, 1);
          } else if (s[j - 1] != s[j] && s[j] == s[j + 1]) {
            // baa
            ft.update(j + 1, 1);
            ft.update(j + 2, -1);
          } else {
            // bab
            ft.update(j + 1, 1);
            ft.update(j + 2, 1);
          }
        }
        s[j] = s[j] == 'A' ? 'B' : 'A';
      } else {
        int l = q[1], r = q[2];
        int op = ft.query(r + 1) - ft.query(l);
        if (l > 0 && s[l] == s[l - 1])
          op--;
        res.push_back(op);
      }
    }

    return res;
  }
};