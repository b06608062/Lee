class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    stack<TreeNode *> st;

    vector<int> res;
    TreeNode *cur = root;
    while (cur || !st.empty()) {
      while (cur) {
        st.push(cur);
        cur = cur->left;
      }

      cur = st.top();
      st.pop();
      res.push_back(cur->val);

      cur = cur->right;
    }

    return res;
  }
};
