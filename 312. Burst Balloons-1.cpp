// reverse interval DP
class Solution {
public:
  int maxCoins(vector<int> &nums) {
    int n = nums.size();

    vector<vector<int>> f(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        int best = 0;
        for (int k = i; k <= j; ++k) {
          int left = k > i ? f[i][k - 1] : 0;
          int mid = (i - 1 >= 0 ? nums[i - 1] : 1) * nums[k] *
                    (j + 1 < n ? nums[j + 1] : 1);
          int right = k < j ? f[k + 1][j] : 0;
          best = max(best, left + mid + right);
        }
        f[i][j] = best;
      }
    }

    return f[0][n - 1];
  }
};

class Solution {
public:
  int maxCoins(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> f(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        for (int k = i; k <= j; ++k) {
          int l_f = k > i ? f[i][k - 1] : 0;
          int l_v = i - 1 >= 0 ? nums[i - 1] : 1;
          int r_v = j + 1 < n ? nums[j + 1] : 1;
          int r_f = k < j ? f[k + 1][j] : 0;
          f[i][j] = max(f[i][j], l_f + l_v * nums[k] * r_v + r_f);
        }
      }
    }
    return f[0][n - 1];
  }
};

class Solution {
public:
  int maxCoins(vector<int> &nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    vector<vector<int>> f(n + 2, vector<int>(n + 2, 0));
    for (int l = n; l >= 1; l--)
      for (int r = l; r <= n; r++)
        for (int i = l; i <= r; i++)
          f[l][r] =
              max(f[l][r], f[l][i - 1] + nums[l - 1] * nums[i] * nums[r + 1] +
                               f[i + 1][r]);

    return f[1][n];
  }
};