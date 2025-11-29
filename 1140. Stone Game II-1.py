class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        suff = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            suff[i] = suff[i + 1] + piles[i]

        @cache
        def dfs(i, M) -> int:
            if i == n:
                return 0
            if i + 2 * M - 1 >= n - 1:
                return suff[i]
            cur = 0
            best = -inf
            for X in range(1, 2 * M + 1, 1):
                j = i + X - 1
                cur += piles[j]
                best = max(best, cur - dfs(j + 1, max(X, M)))
            return best

        return (sum(piles) + dfs(0, 1)) // 2
