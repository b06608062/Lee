class Solution {
public:
  bool isHappy(int n) {
    unordered_set<int> uset;

    while (true) {
      uset.insert(n);

      int sum = 0;
      while (n > 0) {
        sum += pow(n % 10, 2);
        n /= 10;
      }

      n = sum;
      if (n == 1)
        return true;
      else if (uset.count(n))
        return false;
    }
  }
};