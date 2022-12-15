class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        ans = 0
        s, g = 0, 0
        while start != 0 or goal != 0:
            s = (start & 1)
            g = (goal & 1)
            if s != g: ans += 1
            start >>= 1
            goal >>= 1
        return ans
solution = Solution()
solution.minBitFlips(10, 7)