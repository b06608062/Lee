class Solution:
    def minCameraCover(self, root: Optional[TreeNode]) -> int:
        def dfs(node):
            if node is None:
                return inf, 0, 0
            l_choose, l_by_fa, l_by_children = dfs(node.left)
            r_choose, r_by_fa, r_by_children = dfs(node.right)
            choose = min(l_choose, l_by_fa) + min(r_choose, r_by_fa) + 1
            by_fa = min(l_choose, l_by_children) + min(r_choose, r_by_children)
            by_children = min(
                l_choose + r_by_children, l_by_children + r_choose, l_choose + r_choose
            )
            return choose, by_fa, by_children

        choose, _, by_children = dfs(root)
        return min(choose, by_children)
