class Solution {
public:
  long long maxRunTime(int n, vector<int> &batteries) {
    int m = batteries.size();
    sort(batteries.begin(), batteries.end());
    long long total = accumulate(batteries.begin(), batteries.end(), 0ll);

    for (int i = m - 1; i >= 0; --i) {
      if (batteries[i] <= total / n)
        break;
      total -= batteries[i];
      n--;
    }

    return total / n;
  }
};