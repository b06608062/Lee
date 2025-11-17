class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        n = len(nums)

        def swap(x, y):
            return y, x

        def dfs(i):
            if i == n:
                res.append(nums.copy())
                return
            for j in range(i, n):
                nums[i], nums[j] = swap(nums[i], nums[j])
                dfs(i + 1)
                nums[i], nums[j] = swap(nums[i], nums[j])

        dfs(0)
        return res
