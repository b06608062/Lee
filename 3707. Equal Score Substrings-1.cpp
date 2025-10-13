class Solution {
public:
  bool scoreBalance(string s) {
    int sum = 0;
    for (auto ch : s)
      sum += ch - 'a' + 1;

    if (sum % 2)
      return false;

    int n = s.size();
    int target = sum / 2;

    int curSum = 0;
    for (int i = 0; i < n; ++i) {
      curSum += s[i] - 'a' + 1;
      if (curSum == target)
        return true;
      else if (curSum > target)
        return false;
    }

    return false;
  }
};