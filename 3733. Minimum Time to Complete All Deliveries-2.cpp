class Solution {
public:
  long long minimumTime(vector<int> &d, vector<int> &r) {
    long long a = r[0], b = r[1], c = 1LL * a * b / gcd(a, b);
    auto f = [](long long d, long long r) -> long long {
      return d + (d - 1) / (r - 1);
    };

    return max(f(d[0], a), max(f(d[1], b), f(0LL + d[0] + d[1], c)));
  }
};