class Solution:
    def minLengthAfterRemovals(self, s: str) -> int:
        cntA = cntB = 0
        for x in s:
            if x == "a":
                cntA += 1
            else:
                cntB += 1
        return abs(cntA - cntB)
