class Solution {
public:
  long long minCost(string s, vector<int> &cost) {
    int n = s.size();

    vector<long long> cnt(26, 0);

    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += cost[i];
      cnt[s[i] - 'a'] += cost[i];
    }

    return sum - *max_element(cnt.begin(), cnt.end());
  }
};