# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        res = 0

        def dfs(root):
            if root is None:
                return 0
            l_len = dfs(root.left)
            r_len = dfs(root.right)
            nonlocal res
            res = max(res, l_len + r_len)
            return max(l_len, r_len) + 1

        dfs(root)

        return res
