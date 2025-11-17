class Solution:
    def minScoreTriangulation(self, values: List[int]) -> int:
        n = len(values)

        @cache
        def dfs(i, j):
            if i + 1 == j:
                return 0
            res = inf
            for k in range(i + 1, j):
                res = min(
                    res, dfs(i, k) + dfs(k, j) + values[i] * values[j] * values[k]
                )
            return res

        return dfs(0, n - 1)
