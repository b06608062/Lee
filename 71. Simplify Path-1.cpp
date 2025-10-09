class Solution {
public:
  string simplifyPath(string path) {
    int n = path.size();
    vector<string> st; // Stack to store valid path tokens

    int i = 0;
    // Traverse the path string
    while (i < n) {
      // Skip consecutive '/'
      while (i < n && path[i] == '/')
        i++;

      if (i >= n)
        break; // Exit if reached the end

      // Find the end of the current token (until the next '/')
      int j = i;
      while (j < n && path[j] != '/')
        j++;

      // Extract the token from the path
      string token = path.substr(i, j - i);

      // Process the token
      if (token == ".") {
        // Current directory, do nothing
      } else if (token == "..") {
        // Go back to the previous directory if possible
        if (!st.empty())
          st.pop_back();
      } else
        // Valid directory name, add it to the stack
        st.push_back(token);

      // Move to the next part of the path
      i = j;
    }

    // Reconstruct the simplified path from the stack
    string res;
    for (const string &dir : st)
      res += "/" + dir;

    // Return the reconstructed path or "/" if empty
    return res.empty() ? "/" : res;
  }
};
