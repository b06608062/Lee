class Solution {
public:
  int countCollisions(string directions) {
    stack<char> st;

    int res = 0;
    for (auto ch : directions) {
      if (ch == 'S') {
        while (!st.empty() && st.top() == 'R') {
          res++;
          st.pop();
        }
        st.push('S');
      } else if (ch == 'L') {
        if (!st.empty()) {
          if (st.top() == 'S')
            res++;
          else {
            // R
            res += 2;
            st.pop();
            while (!st.empty() && st.top() == 'R') {
              res++;
              st.pop();
            }
            st.push('S');
          }
        }
      } else
        st.push('R');
    }

    return res;
  }
};