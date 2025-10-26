class Solution {
public:
  int distMoney(int money, int children) {
    if (money / 8 >= children)
      if (money % 8 || money / 8 > children)
        return children - 1;
      else
        return children;

    if (money < children)
      return -1;

    money -= children;

    int res = money / 7, remain = money % 7;
    if (children - res == 1 && remain == 3)
      res--;

    return res;
  }
};