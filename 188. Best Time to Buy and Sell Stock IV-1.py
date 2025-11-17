class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        n = len(prices)

        @cache
        def dfs(i, j, hold):
            if j < 0:
                return -inf
            if i < 0:
                return -inf if hold else 0
            if hold:
                return max(dfs(i - 1, j, 1), dfs(i - 1, j - 1, 0) - prices[i])
            else:
                return max(dfs(i - 1, j, 0), dfs(i - 1, j, 1) + prices[i])

        return dfs(n - 1, k, 0)
