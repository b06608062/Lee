class Solution {
public:
  int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k) {
    int n = reward1.size();

    vector<int> diff;
    for (int i = 0; i < n; ++i)
      diff.push_back(reward2[i] - reward1[i]);
    sort(diff.rbegin(), diff.rend());

    int res = accumulate(reward1.begin(), reward1.end(), 0);
    if (k < n) {
      for (auto d : diff) {
        res += d;
        if (++k == n)
          break;
      }
    }

    return res;
  }
};