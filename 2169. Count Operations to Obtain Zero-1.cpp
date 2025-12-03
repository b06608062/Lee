class Solution {
public:
  int countOperations(int num1, int num2) {
    int res = 0;
    while (num1 && num2) {
      if (num1 < num2)
        swap(num1, num2);
      num1 -= num2;
      res++;
    }

    return res;
  }
};

class Solution {
public:
  int countOperations(int n1, int n2) {
    int res = 0;
    while (n1 > 0 && n2 > 0) {
      res += n1 / n2;
      n1 %= n2;
      swap(n1, n2);
    }
    return res;
  }
};