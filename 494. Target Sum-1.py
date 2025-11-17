def zero_one_knapsack(capacity: int, w: List[int], v: List[int]) -> int:
    n = len(w)

    @cache
    def dfs(i, c):
        if i < 0:
            return 0
        if c < w[i]:
            return dfs(i - 1, c)
        return max(dfs(i - 1, c), dfs(i - 1, c - w[i]) + v[i])

    return dfs(n - 1, capacity)


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

        n = len(nums)

        @cache
        def dfs(i, c):
            if i < 0:
                return 1 if c == 0 else 0
            if c < nums[i]:
                return dfs(i - 1, c)
            return dfs(i - 1, c) + dfs(i - 1, c - nums[i])

        return dfs(n - 1, target)


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

        n = len(nums)

        @cache
        def dfs(i, c):
            if i < 0:
                return 1
            if c < nums[i]:
                return dfs(i - 1, c)
            return dfs(i - 1, c) + dfs(i - 1, c - nums[i])

        return dfs(n - 1, target)


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

        n = len(nums)

        @cache
        def dfs(i, c):
            if i < 0:
                return 1 if c <= 0 else 0
            return dfs(i - 1, c) + dfs(i - 1, c - nums[i])

        return dfs(n - 1, target)
