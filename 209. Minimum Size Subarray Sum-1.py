class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        res = n + 1
        s = 0
        left = 0
        for right, x in enumerate(nums):
            s += x
            while s >= target:
                res = min(res, right - left + 1)
                s -= nums[left]
                left += 1

        return res if res != n + 1 else 0
