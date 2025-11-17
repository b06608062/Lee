class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        # p
        # s - p
        # p - (s - p) = t
        # 2p = s + t
        # p = (s + t) / 2
        target += sum(nums)
        if target < 0 or target % 2:
            return 0
        target //= 2

        n = len(nums)

        f = [[0] * (target + 1) for _ in range(2)]
        f[0][0] = 1

        for i, x in enumerate(nums):
            for c in range(target + 1):
                if c < x:
                    f[(i + 1) % 2][c] = f[i % 2][c]
                else:
                    f[(i + 1) % 2][c] = f[i % 2][c] + f[i % 2][c - x]

        return f[n % 2][target]
