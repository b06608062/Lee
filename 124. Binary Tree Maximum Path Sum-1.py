# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        res = -inf

        def dfs(root):
            if root is None:
                return 0
            x = root.val
            l_len = dfs(root.left)
            r_len = dfs(root.right)
            t_len = x
            if l_len > 0:
                t_len += l_len
            if r_len > 0:
                t_len += r_len
            nonlocal res
            res = max(res, t_len)
            return max(x, max(x + l_len, x + r_len))

        dfs(root)
        return res
