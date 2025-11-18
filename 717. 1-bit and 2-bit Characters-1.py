class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        n = len(bits)
        i = 0
        while i < n:
            if bits[i] == 1:
                i += 2
            elif i == n - 1:
                return True
            else:
                i += 1

        return False
