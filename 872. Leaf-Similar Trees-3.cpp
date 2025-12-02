class Solution {
public:
  int nextLeaf(stack<TreeNode *> &st) {
    while (!st.empty()) {
      TreeNode *node = st.top();
      st.pop();

      if (!node->left && !node->right)
        return node->val;

      if (node->right)
        st.push(node->right);
      if (node->left)
        st.push(node->left);
    }
    return -1;
  }

  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    stack<TreeNode *> st1, st2;
    if (root1)
      st1.push(root1);
    if (root2)
      st2.push(root2);

    while (true) {
      int leaf1 = nextLeaf(st1);
      int leaf2 = nextLeaf(st2);

      if (leaf1 == -1 && leaf2 == -1)
        return true;

      if (leaf1 != leaf2)
        return false;
    }
  }
};
