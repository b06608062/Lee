class Solution:
    def countDistinct(self, n: int) -> int:
        s = str(n)
        m = len(s)

        pow9 = 9**m
        res = (pow9 - 9) // 8

        for i, d in enumerate(s):
            if d == "0":
                break
            v = int(d) - 1
            if i == m - 1:
                v += 1
            pow9 //= 9
            res += v * pow9

        return res
