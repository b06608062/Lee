def unbounded_knapsack(capacity: int, w: List[int], v: List[int]) -> int:
    n = len(w)

    @cache
    def dfs(i, c):
        if i < 0:
            return 0
        if c < w[i]:
            return dfs(i - 1, c)
        return max(dfs(i - 1, c), dfs(i, c - w[i]) + v[i])

    return dfs(n - 1, capacity)


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)

        @cache
        def dfs(i, c):
            if i < 0:
                return 0 if c == 0 else inf
            if c < coins[i]:
                return dfs(i - 1, c)
            return min(dfs(i - 1, c), dfs(i, c - coins[i]) + 1)

        res = dfs(n - 1, amount)
        return res if res < inf else -1
