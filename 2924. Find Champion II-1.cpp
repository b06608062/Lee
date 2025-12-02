class Solution {
public:
  int findChampion(int n, vector<vector<int>> &edges) {
    vector<int> indeg(n, 0);
    for (auto &e : edges)
      indeg[e[1]]++;

    int cnt = 0;
    for (auto in : indeg)
      if (in == 0)
        cnt++;
    if (cnt > 1)
      return -1;

    for (int i = 0; i < n; ++i)
      if (indeg[i] == 0)
        return i;

    return -1;
  }
};