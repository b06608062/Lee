class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        res = []
        place = [0] * n
        col = [False] * n
        m = 2 * n - 1
        diag1 = [False] * m
        diag2 = [False] * m

        def dfs(i):
            if i == n:
                res.append(["." * j + "Q" + "." * (n - 1 - j) for j in place])
                return
            for j in range(n):
                if not col[j] and not diag1[i + j] and not diag2[i - j]:
                    place[i] = j
                    col[j] = diag1[i + j] = diag2[i - j] = True
                    dfs(i + 1)
                    col[j] = diag1[i + j] = diag2[i - j] = False

        dfs(0)
        return res
