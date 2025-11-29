class Solution {
public:
  vector<int> used;
  int n, target;
  bool makesquare(vector<int> &matchsticks) {
    int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    if (sum % 4)
      return false;

    n = matchsticks.size();
    used.assign(n, 0);
    target = sum / 4;
    sort(matchsticks.rbegin(), matchsticks.rend());

    return dfs(matchsticks, 0, 0, 0);
  }

  bool dfs(vector<int> &matchsticks, int i, int cur, int group) {
    if (group == 4)
      return true;
    if (cur == target)
      return dfs(matchsticks, 0, 0, group + 1);
    if (cur > target)
      return false;

    for (int j = i; j < n; ++j) {
      if ((j > i && matchsticks[j] == matchsticks[j - 1] && !used[j - 1]) ||
          used[j])
        continue;
      used[j] = 1;
      if (dfs(matchsticks, j + 1, cur + matchsticks[j], group))
        return true;
      used[j] = 0;
    }

    return false;
  }
};