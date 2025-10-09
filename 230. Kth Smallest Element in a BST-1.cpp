class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    stack<TreeNode *> st;

    TreeNode *cur = root;
    while (cur || !st.empty()) {
      while (cur != nullptr) {
        st.push(cur);
        cur = cur->left;
      }

      cur = st.top();
      st.pop();
      if (--k == 0)
        return cur->val;

      cur = cur->right;
    }

    return -1;
  }
};