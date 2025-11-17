class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        n = len(nums)
        path = [0] * n

        def dfs(i, s):
            if i == n:
                res.append(path.copy())
                return
            for x in s:
                path[i] = x
                dfs(i + 1, s - {x})

        dfs(0, set(nums))
        return res
