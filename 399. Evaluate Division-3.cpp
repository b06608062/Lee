class Solution {
public:
  vector<double> calcEquation(vector<vector<string>> &equations,
                              vector<double> &values,
                              vector<vector<string>> &queries) {
    for (int i = 0; i < equations.size(); ++i) {
      string &A = equations[i][0];
      string &B = equations[i][1];
      double val = values[i];
      if (!parents.count(A) && !parents.count(B)) {
        parents[A] = {B, val};
        parents[B] = {B, 1.0};
      } else if (!parents.count(A))
        parents[A] = {B, val};
      else if (!parents.count(B))
        parents[B] = {A, 1.0 / val};
      else {
        auto &rA = find(A); // {rA, A / rA}
        auto &rB = find(B); // {rB, B / rB}
        parents[rA.first] = {rB.first, (rB.second / rA.second) * val};
      }
    }

    vector<double> res;
    for (auto &q : queries) {
      string &A = q[0];
      string &B = q[1];
      if (!parents.count(A) || !parents.count(B)) {
        res.push_back(-1.0);
        continue;
      }
      auto &rA = find(A); // {rA, A / rA}
      auto &rB = find(B); // {rB, B / rB}
      if (rA.first != rB.first)
        res.push_back(-1.0);
      else
        res.push_back(rA.second / rB.second);
    }

    return res;
  }

  unordered_map<string, pair<string, double>> parents;
  pair<string, double> &find(string &X) {
    if (X != parents[X].first) {
      auto &p = find(parents[X].first);
      parents[X].first = p.first;
      parents[X].second *= p.second;
    }

    return parents[X];
  }
};