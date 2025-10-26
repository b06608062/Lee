class Bank {
public:
  int n;
  vector<long long> acc;
  Bank(vector<long long> &balance) {
    n = balance.size();
    acc = vector<long long>(n + 1);
    for (int i = 0; i < n; ++i)
      acc[i + 1] = balance[i];
  }

  bool transfer(int account1, int account2, long long money) {
    if (account1 > n || acc[account1] < money || account2 > n)
      return false;
    acc[account1] -= money;
    acc[account2] += money;
    return true;
  }

  bool deposit(int account, long long money) {
    if (account > n)
      return false;
    acc[account] += money;
    return true;
  }

  bool withdraw(int account, long long money) {
    if (account > n || acc[account] < money)
      return false;
    acc[account] -= money;
    return true;
  }
};