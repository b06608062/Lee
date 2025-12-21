// mark
// ???
// 模擬 + 狀態反轉 + 等差數列
class Solution {
public:
  long long lastInteger(long long n) {
    long long head = 1, step = 1, cnt = n;
    bool op1 = true;
    while (cnt > 1) {
      if (!op1 && cnt % 2 == 0)
        head += step;
      step *= 2;
      cnt = (cnt + 1) / 2;
      op1 = !op1;
    }

    return head;
  }
};