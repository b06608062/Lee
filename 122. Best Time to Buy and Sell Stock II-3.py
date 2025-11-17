class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)

        f0 = 0
        f1 = -inf
        for p in prices:
            new_f0 = max(f0, f1 + p)
            f1 = max(f1, f0 - p)
            f0 = new_f0

        return f0
