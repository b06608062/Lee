class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < abs(target))
      return 0;

    int n = nums.size();
    vector<vector<int>> f(n + 1, vector<int>(sum * 2 + 1, 0));

    int offset = sum;
    f[0][offset] = 1;
    for (int i = 1; i <= n; ++i) {
      int x = nums[i - 1];
      for (int j = 0; j < sum * 2 + 1; ++j) {
        if (!f[i - 1][j])
          continue;
        if (j - x >= 0)
          f[i][j - x] += f[i - 1][j];
        if (j + x < sum * 2 + 1)
          f[i][j + x] += f[i - 1][j];
      }
    }

    return f[n][target + offset];
  }
};

class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < abs(target))
      return 0;
    int offset = sum;
    vector<vector<int>> f(n + 1, vector<int>(sum * 2 + 1, 0));
    // f[i][j] = f[i - 1][j - x] + f[i - 1][j + x]
    f[0][offset] = 1;
    for (int i = 1; i <= n; ++i) {
      int x = nums[i - 1];
      for (int j = 0; j < sum * 2 + 1; ++j) {
        if (j - x >= 0)
          f[i][j] += f[i - 1][j - x];
        if (j + x < sum * 2 + 1)
          f[i][j] += f[i - 1][j + x];
      }
    }

    return f[n][offset + target];
  }
};

class Solution {
public:
  vector<vector<int>> memo;
  int offset;
  int findTargetSumWays(vector<int> &nums, int target) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (abs(target) > sum)
      return 0;
    offset = sum;
    memo.assign(n, vector<int>(sum * 2 + 1, -1));
    return dfs(nums, n - 1, target);
  }

  int dfs(vector<int> &nums, int i, int a) {
    if (i < 0)
      return a == 0 ? 1 : 0;
    int &res = memo[i][a + offset];
    if (res != -1)
      return res;

    return res = dfs(nums, i - 1, a - nums[i]) + dfs(nums, i - 1, a + nums[i]);
  }
};

class Solution {
public:
  vector<vector<int>> memo;
  int sum, offset;
  int findTargetSumWays(vector<int> &nums, int target) {
    int n = nums.size();
    sum = accumulate(nums.begin(), nums.end(), 0);
    if (abs(target) > sum)
      return 0;
    offset = sum;
    memo.assign(n, vector<int>(sum * 2 + 1, -1));
    return dfs(nums, n - 1, offset + target);
  }

  int dfs(vector<int> &nums, int i, int a) {
    if (a < 0 || a > sum * 2)
      return 0;
    if (i < 0)
      return a == offset ? 1 : 0;
    int &res = memo[i][a];
    if (res != -1)
      return res;
    return res = dfs(nums, i - 1, a - nums[i]) + dfs(nums, i - 1, a + nums[i]);
  }
};

class Solution {
public:
  vector<vector<int>> memo;
  int sum, offset;
  int findTargetSumWays(vector<int> &nums, int target) {
    int n = nums.size();
    sum = accumulate(nums.begin(), nums.end(), 0);
    if (abs(target) > sum)
      return 0;
    offset = sum;
    memo.assign(n, vector<int>(sum * 2 + 1, -1));
    return dfs(nums, n - 1, offset + target);
  }

  int dfs(vector<int> &nums, int i, int a) {
    if (i < 0 || a < 0 || a > sum * 2)
      return a == offset ? 1 : 0;
    int &res = memo[i][a];
    if (res != -1)
      return res;
    return res = dfs(nums, i - 1, a - nums[i]) + dfs(nums, i - 1, a + nums[i]);
  }
};