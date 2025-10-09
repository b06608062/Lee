class Solution {
public:
  bool isHappy(int n) {
    unordered_set<int> uset;

    while (true) {
      uset.insert(n);

      string s = to_string(n);
      n = 0;
      for (auto ch : s)
        n += pow(ch - '0', 2);

      if (n == 1)
        return true;
      else if (uset.count(n))
        return false;
    }
  }
};