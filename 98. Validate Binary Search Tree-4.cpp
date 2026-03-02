class Solution {
public:
  bool isValidBST(TreeNode *root) {
    TreeNode *pre = nullptr, *cur = root;
    stack<TreeNode *> st;
    while (cur || !st.empty()) {
      while (cur) {
        st.push(cur);
        cur = cur->left;
      }
      cur = st.top();
      st.pop();
      if (pre && cur->val <= pre->val)
        return false;
      pre = cur;
      cur = cur->right;
    }
    return true;
  }
};