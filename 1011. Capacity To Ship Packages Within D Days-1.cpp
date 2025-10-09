class Solution {
public:
  int shipWithinDays(vector<int> &weights, int days) {
    int sum = 0, maxW = 0;
    for (auto x : weights) {
      sum += x;
      maxW = max(maxW, x);
    }

    int l = maxW, r = sum;
    while (l < r) {
      int carry = (l + r) / 2;
      if (eval(weights, carry) > days)
        l = carry + 1;
      else
        r = carry;
    }

    return l;
  }

  int eval(vector<int> &weights, int carry) {
    int load = 0, day = 1;
    for (auto x : weights) {
      load += x;
      if (load > carry) {
        day++;
        load = x;
      }
    }

    return day;
  }
};