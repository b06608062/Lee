class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        f0 = f1 = 0
        for x in nums:
            new_f = max(f1, f0 + x)
            f0 = f1
            f1 = new_f
        return f1
