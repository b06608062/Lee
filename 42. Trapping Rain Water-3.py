class Solution:
    def trap(self, height: List[int]) -> int:
        res = 0
        st = []
        for i, h in enumerate(height):
            while st and height[st[-1]] <= h:
                bottom_h = height[st.pop()]
                if not st:
                    break
                left = st[-1]
                dh = min(height[left], h) - bottom_h
                res += dh * (i - left - 1)
            st.append(i)
        return res
