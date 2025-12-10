class Solution:
    def countCoprime(self, mat: List[List[int]]) -> int:
        MOD = 1_000_000_007

        @cache
        def dfs(i, g) -> int:
            if i < 0:
                return 1 if g == 1 else 0
            return sum(dfs(i - 1, gcd(g, x)) for x in mat[i]) % MOD

        return dfs(len(mat) - 1, 0)
