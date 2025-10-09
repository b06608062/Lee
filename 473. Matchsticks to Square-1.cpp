class Solution {
public:
  vector<int> used;
  int target;
  bool makesquare(vector<int> &matchsticks) {
    int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    if (sum % 4)
      return false;

    used = vector<int>(matchsticks.size(), 0);
    target = sum / 4;

    sort(matchsticks.rbegin(), matchsticks.rend());

    return helper(matchsticks, 0, 0, 0);
  }
  bool helper(vector<int> &matchsticks, int group, int curSum, int start) {
    if (group == 4)
      return true;
    if (curSum == target)
      return helper(matchsticks, group + 1, 0, 0);
    else if (curSum > target)
      return false;

    unordered_set<int> uset;
    for (int i = start; i < matchsticks.size(); ++i) {
      int x = matchsticks[i];
      if (!used[i] && !uset.count(x)) {
        used[i] = 1;
        uset.insert(x);
        if (helper(matchsticks, group, curSum + x, i + 1))
          return true;
        used[i] = 0;
      }
    }

    return false;
  }
};