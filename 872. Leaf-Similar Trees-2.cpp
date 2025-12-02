class Solution {
public:
  vector<int> getLeaves(TreeNode *root) {
    vector<int> leaves;
    if (!root)
      return leaves;

    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty()) {
      TreeNode *node = st.top();
      st.pop();

      if (!node->left && !node->right) {
        leaves.push_back(node->val);
      }

      if (node->right)
        st.push(node->right);
      if (node->left)
        st.push(node->left);
    }

    return leaves;
  }

  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    return getLeaves(root1) == getLeaves(root2);
  }
};
