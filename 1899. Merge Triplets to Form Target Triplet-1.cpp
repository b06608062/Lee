class Solution {
public:
  bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target) {
    vector<int> solve(3, 0);

    int a = target[0], b = target[1], c = target[2];
    for (auto x : triplets)
      if (x[0] <= a && x[1] <= b && x[2] <= c) {
        if (x[0] == a)
          solve[0] = 1;
        if (x[1] == b)
          solve[1] = 1;
        if (x[2] == c)
          solve[2] = 1;
      }

    return solve[0] && solve[1] && solve[2];
  }
};