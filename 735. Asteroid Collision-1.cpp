class Solution {
public:
  vector<int> asteroidCollision(vector<int> &asteroids) {
    stack<int> st;
    for (auto as : asteroids) {
      if (as > 0)
        st.push(as);
      else {
        // as < 0
        while (!st.empty() && st.top() > 0 && st.top() < abs(as))
          st.pop();
        if (st.empty() || st.top() < 0)
          st.push(as);
        else if (st.top() == abs(as))
          st.pop();
      }
    }

    int n = st.size();
    vector<int> res(n);
    for (int i = n - 1; i >= 0; --i) {
      res[i] = st.top();
      st.pop();
    }

    return res;
  }
};