class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res = []
        path = []

        def dfs(i, t):
            if t < 0:
                return
            if len(path) == k:
                if t == 0:
                    res.append(path.copy())
                return
            if i + len(path) < k:
                return
            for j in range(i, 0, -1):
                path.append(j)
                dfs(j - 1, t - j)
                path.pop()

        dfs(9, n)
        return res
