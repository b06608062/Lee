class Solution {
public:
  vector<int> getGoodIndices(vector<vector<int>> &variables, int target) {
    int n = variables.size();
    vector<int> res;

    for (int i = 0; i < n; ++i) {
      auto &v = variables[i];
      int a = v[0], b = v[1], c = v[2], d = v[3];
      int n1 = 1;
      while (b) {
        n1 *= (b % 2) ? a : 1;
        n1 %= 10;
        a *= a;
        a %= 10;
        b /= 2;
      }

      int n2 = 1;
      while (c) {
        n2 *= (c % 2) ? n1 : 1;
        n2 %= d;
        n1 *= n1;
        n1 %= d;
        c /= 2;
      }

      if (n2 == target)
        res.push_back(i);
    }

    return res;
  }
};