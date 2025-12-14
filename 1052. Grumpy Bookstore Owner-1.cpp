class Solution {
public:
  int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
    int n = customers.size();

    int cur = 0, mx = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
      if (i - minutes >= 0)
        if (grumpy[i - minutes])
          cur -= customers[i - minutes];
      if (grumpy[i])
        cur += customers[i];
      else
        sum += customers[i];
      mx = max(mx, cur);
    }

    return sum + mx;
  }
};