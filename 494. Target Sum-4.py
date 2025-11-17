# 恰好 target
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

        f = [0] * (target + 1)
        f[0] = 1

        for x in nums:
            for c in range(target, x - 1, -1):
                f[c] += f[c - x]

        return f[target]


# 至多 target
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

        f = [1] * (target + 1)

        for x in nums:
            for c in range(target, x - 1, -1):
                f[c] += f[c - x]

        return f[target]


# 至少 target
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

        f = [0] * (target + 1)
        f[0] = 1

        for x in nums:
            for c in range(target, -1, -1):
                f[c] += f[max(c - x, 0)]

        return f[target]
