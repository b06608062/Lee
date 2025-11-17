class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        t = s[::-1]

        f = [[0] * (n + 1) for _ in range(n + 1)]

        for i, x in enumerate(s):
            for j, y in enumerate(t):
                if x == y:
                    f[i + 1][j + 1] = f[i][j] + 1
                else:
                    f[i + 1][j + 1] = max(f[i][j + 1], f[i + 1][j])

        return f[n][n]
