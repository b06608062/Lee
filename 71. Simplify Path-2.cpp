class Solution {
public:
  string simplifyPath(string path) {
    vector<string> st;
    string token;
    stringstream ss(path);

    // 以 '/' 分割
    while (getline(ss, token, '/')) {
      if (token.empty() || token == ".")
        continue; // 跳過空與 .
      if (token == "..") {
        if (!st.empty())
          st.pop_back(); // 回上一層
      } else
        st.push_back(token); // 正常目錄名
    }

    // 組回結果
    if (st.empty())
      return "/";

    string res;
    for (int i = 0; i < st.size(); ++i)
      res += '/' + st[i];

    return res;
  }
};