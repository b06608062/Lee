class Solution {
public:
  vector<int> decimalRepresentation(int n) {
    vector<int> res;

    long long p = 1;
    while (n) {
      int digit = n % 10;
      if (digit)
        res.push_back(digit * p);
      p *= 10, n /= 10;
    }

    reverse(res.begin(), res.end());

    return res;
  }
};