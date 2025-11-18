class Solution {
public:
  int cameras = 0;

  // 0 = NOT_COVERED
  // 1 = HAS_CAMERA
  // 2 = COVERED
  int dfs(TreeNode *node) {
    if (!node)
      return 2; // 空節點視為 COVERED，避免放相機

    int left = dfs(node->left);
    int right = dfs(node->right);

    // 若任一子節點沒有被覆蓋 → 我必須放相機
    if (left == 0 || right == 0) {
      cameras++;
      return 1; // HAS_CAMERA
    }

    // 若任一子節點有相機 → 我已被覆蓋
    if (left == 1 || right == 1) {
      return 2; // COVERED
    }

    // 否則 → 我沒相機，也沒有被子節點覆蓋
    return 0; // NOT_COVERED
  }

  int minCameraCover(TreeNode *root) {
    if (dfs(root) == 0) {
      cameras++; // root 沒被覆蓋 → 加一台
    }
    return cameras;
  }
};
