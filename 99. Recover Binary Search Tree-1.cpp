class Solution {
public:
  void recoverTree(TreeNode *root) {
    TreeNode *first = nullptr, *second = nullptr;
    TreeNode *prev = nullptr, *cur = root;
    stack<TreeNode *> st;
    while (cur || !st.empty()) {
      while (cur) {
        st.push(cur);
        cur = cur->left;
      }
      cur = st.top();
      st.pop();
      if (prev && cur->val <= prev->val) {
        if (!first)
          first = prev;
        second = cur;
      }
      prev = cur;
      cur = cur->right;
    }
    swap(first->val, second->val);
  }
};