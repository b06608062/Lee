class Solution {
public:
  vector<int> cycleLengthQueries(int n, vector<vector<int>> &queries) {
    vector<int> res;

    for (auto &q : queries) {
      int a = q[0], b = q[1];
      int cntA = 0, cntB = 0;
      while (a != b) {
        if (a > b) {
          a /= 2;
          cntA++;
        } else {
          b /= 2;
          cntB++;
        }
      }
      res.push_back(cntA + cntB + 1);
    }

    return res;
  }
};