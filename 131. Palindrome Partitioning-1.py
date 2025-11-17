class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = []
        path = []
        n = len(s)

        def dfs(i):
            if i == n:
                res.append(path.copy())
            for j in range(i, n):
                t = s[i : j + 1]
                if t == t[::-1]:
                    path.append(t)
                    dfs(j + 1)
                    path.pop()

        dfs(0)
        return res
