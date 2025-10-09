class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> st;
    for (string &token : tokens) {
      if (token == "+" || token == "-" || token == "*" || token == "/") {
        int num2 = st.top();
        st.pop();
        int num1 = st.top();
        st.pop();
        if (token == "+")
          st.push(num1 + num2);
        else if (token == "-")
          st.push(num1 - num2);
        else if (token == "*")
          st.push(num1 * num2);
        else
          st.push(num1 / num2);

      } else
        st.push(stoi(token));
    }

    return st.top();
  }
};