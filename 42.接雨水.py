#
# @lc app=leetcode.cn id=42 lang=python3
#
# [42] 接雨水
#

# @lc code=start
from email import header
from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        stack = []
        ans = 0
        n = len(height)
        for index in range(n):
            h = height[index]
            while stack and height[stack[-1]] <= h:
                rightEdge = stack.pop()
                if stack:
                    ans += (min(height[stack[-1]], h) - height[rightEdge]) * (index - stack[-1] - 1)
            stack.append(index)
        return ans
# @lc code=end

