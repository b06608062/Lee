class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        t = s[::-1]

        @cache
        def dfs(i, j):
            if i < 0:
                return 0
            if j < 0:
                return 0
            if s[i] == t[j]:
                return dfs(i - 1, j - 1) + 1
            else:
                return max(dfs(i - 1, j), dfs(i, j - 1))

        return dfs(n - 1, n - 1)
