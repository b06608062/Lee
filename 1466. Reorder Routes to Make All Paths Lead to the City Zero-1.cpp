class Solution {
public:
  int minReorder(int n, vector<vector<int>> &connections) {
    vector<bool> vis(n, false);
    vector<vector<int>> in(n), out(n);
    for (auto &e : connections) {
      int u = e[0], v = e[1];
      out[u].push_back(v);
      in[v].push_back(u);
    }

    stack<int> st;

    vis[0] = true;
    st.push(0);
    int res = 0;
    while (!st.empty()) {
      int u = st.top();
      st.pop();
      for (auto o : out[u])
        if (!vis[o]) {
          res++;
          vis[o] = true;
          st.push(o);
        }
      for (auto i : in[u])
        if (!vis[i]) {
          vis[i] = true;
          st.push(i);
        }
    }

    return res;
  }
};