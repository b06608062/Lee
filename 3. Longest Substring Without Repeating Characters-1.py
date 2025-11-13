class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        res = 0
        cnt = Counter()  # char, int
        left = 0
        for right, ch in enumerate(s):
            cnt[ch] += 1
            while cnt[ch] > 1:
                cnt[s[left]] -= 1
                left += 1
            res = max(res, right - left + 1)

        return res
