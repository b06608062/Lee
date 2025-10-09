class Solution {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    if (!root)
      return res;

    stack<TreeNode *> st;

    st.push(root);
    while (!st.empty()) {
      TreeNode *node = st.top();
      st.pop();
      res.push_back(node->val); // 訪問根
      if (node->right)
        st.push(node->right); // 先推右
      if (node->left)
        st.push(node->left); // 再推左（確保左先處理）
    }

    return res;
  }
};
