class Solution {
public:
  bool isUgly(int n) {
    if (n <= 0)
      return false;

    vector<int> arr{2, 3, 5};
    for (auto x : arr)
      while (n % x == 0)
        n /= x;

    return n == 1;
  }
};