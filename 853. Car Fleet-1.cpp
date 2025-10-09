class Solution {
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed) {
    int n = position.size();

    vector<pair<int, double>> cars(n); // pos, time
    for (int i = 0; i < n; ++i) {
      double t = (double)(target - position[i]) / speed[i];
      cars[i] = {position[i], t};
    }

    sort(cars.begin(), cars.end(),
         [](auto &a, auto &b) { return a.first < b.first; });

    stack<double> st;
    for (int i = n - 1; i >= 0; --i)
      if (st.empty() || cars[i].second > st.top())
        st.push(cars[i].second);

    return st.size();
  }
};