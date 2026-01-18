// mark
// ???
// 排序後枚舉右 + 單調棧

class Solution {
public:
  int maxCapacity(vector<int> &costs, vector<int> &capacity, int budget) {
    int n = costs.size();
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; ++i) {
      if (costs[i] < budget) {
        arr.push_back({costs[i], capacity[i]});
      }
    }

    sort(arr.begin(), arr.end());
    stack<pair<int, int>> st;
    st.push({0, 0});
    int res = 0;
    for (auto &a : arr) {
      auto &[cost, cap] = a;
      while (cost + st.top().first >= budget) {
        st.pop();
      }
      res = max(res, cap + st.top().second);
      if (cap > st.top().second) {
        st.push({cost, cap});
      }
    }

    return res;
  }
};