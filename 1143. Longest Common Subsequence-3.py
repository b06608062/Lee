class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n = len(text1)
        m = len(text2)

        f = [0] * (m + 1)

        for i, x in enumerate(text1):
            pre = f[0]  # 0
            for j, y in enumerate(text2):
                temp = f[j + 1]
                f[j + 1] = pre + 1 if x == y else max(f[j + 1], f[j])
                pre = temp

        return f[m]
