class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)

        f = [inf] * (amount + 1)
        f[0] = 0
        for x in coins:
            for c in range(x, amount + 1):
                f[c] = min(f[c], f[c - x] + 1)

        res = f[amount]
        return res if res < inf else -1
