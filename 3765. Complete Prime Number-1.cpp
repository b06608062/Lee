class Solution {
public:
  bool completePrime(int num) {
    unordered_set<int> uset;

    long long suff = 0, prod = 1;
    while (num) {
      uset.insert(num);
      suff += num % 10 * prod;
      uset.insert(suff);
      prod *= 10;
      num /= 10;
    }

    for (auto x : uset) {
      if (x == 1)
        return false;
      for (int i = 2; i * i <= x; ++i)
        if (x % i == 0)
          return false;
    }

    return true;
  }
};