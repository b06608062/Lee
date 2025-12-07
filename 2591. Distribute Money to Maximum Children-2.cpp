class Solution {
public:
  int distMoney(int money, int children) {
    int res = 0;
    if (money < children)
      return -1;
    if (money > children * 8)
      return children - 1;

    while (money > 0 && money - 8 >= children - 1) {
      money -= 8;
      res++;
      children--;
    }

    if (money == 4 && children == 1)
      res--;

    return res;
  }
};