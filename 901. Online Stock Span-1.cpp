class StockSpanner {
public:
  stack<pair<int, int>> st; // price, day
  int day = 0;
  StockSpanner() {}

  int next(int price) {
    day++;

    while (!st.empty() && price >= st.top().first)
      st.pop();

    int res;
    if (st.empty())
      res = day;
    else
      res = day - st.top().second;

    st.push({price, day});

    return res;
  }
};