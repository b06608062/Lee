class Solution {
public:
  vector<int> sortByBits(vector<int> &arr) {
    sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
      int x = __builtin_popcountll(a), y = __builtin_popcountll(b);
      if (x != y)
        return x < y;
      return a < b;
    });

    return arr;
  }
};