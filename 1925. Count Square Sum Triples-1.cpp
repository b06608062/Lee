class Solution {
public:
  int countTriples(int n) {
    unordered_set<int> uset;
    for (int i = 1; i <= n; ++i)
      uset.insert(i * i);

    int res = 0;
    for (int i = 1; i < n; ++i)
      for (int j = 1; j < n; ++j)
        if (uset.count(i * i + j * j))
          res += 1;
    return res;
  }
};