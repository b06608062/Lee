class Solution {
public:
  vector<bool> checkIfPrerequisite(int numCourses,
                                   vector<vector<int>> &prerequisites,
                                   vector<vector<int>> &queries) {
    vector<vector<bool>> isReachable(numCourses,
                                     vector<bool>(numCourses, false));

    for (auto &p : prerequisites)
      isReachable[p[0]][p[1]] = true;

    for (int k = 0; k < numCourses; ++k)
      for (int i = 0; i < numCourses; ++i) {
        if (!isReachable[i][k] || i == k)
          continue;
        for (int j = 0; j < numCourses; ++j)
          isReachable[i][j] =
              isReachable[i][j] || isReachable[i][k] && isReachable[k][j];
      }

    vector<bool> res;
    for (auto &q : queries)
      res.push_back(isReachable[q[0]][q[1]] ? true : false);

    return res;
  }
};