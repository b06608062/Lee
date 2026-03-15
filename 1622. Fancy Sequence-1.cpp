// mark
// 2476
// y = Ax + B 模型
// A 代表乘法，B 代表加法
// addAll 只會影響 B
// multAll 會同時影響 A 和 B
// append 要抵銷前面 A 和 B 的影響，所以要先減掉 B，再乘上 A 的乘法反元素

class Fancy {
public:
  // y = Ax + B
  long long A = 1, B = 0;
  long long MOD = 1e9 + 7;
  vector<long long> nums;
  long long pow(long long x, long long e) {
    long long res = 1;
    x %= MOD;
    while (e) {
      if (e & 1)
        res = (res * x) % MOD;
      x = (x * x) % MOD;
      e >>= 1;
    }
    return res;
  }
  Fancy() {}

  void append(int val) {
    nums.push_back(((val - B) * pow(A, MOD - 2) % MOD + MOD) % MOD);
  }

  void addAll(int inc) { B = (B + inc) % MOD; }

  void multAll(int m) {
    A = (A * m) % MOD;
    B = (B * m) % MOD;
  }

  int getIndex(int idx) {
    if (idx >= nums.size())
      return -1;
    return (nums[idx] * A + B) % MOD;
  }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */