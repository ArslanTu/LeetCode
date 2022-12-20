#
# @lc app=leetcode.cn id=503 lang=python3
#
# [503] 下一个更大元素 II
#

# @lc code=start
from typing import List


class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        stack = [] # 保存下标和元素
        n = len(nums)
        ans = [-1 for i in range(n)]
        for i in range(2 * n):
            j = i % n
            while stack and stack[-1][1] < nums[j]:
                originPos, _ = stack.pop()
                ans[originPos] = nums[j]
            stack.append([j, nums[j]])
        return ans
# @lc code=end

