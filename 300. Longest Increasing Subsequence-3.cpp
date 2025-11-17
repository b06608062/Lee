class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    vector<int> g;
    for (auto x : nums) {
      int j = lower_bound(g.begin(), g.end(), x) - g.begin();
      if (j == g.size())
        g.push_back(x);
      else
        g[j] = x;
    }

    return g.size();
  }
};