#
# @lc app=leetcode.cn id=739 lang=python3
#
# [739] 每日温度
#

# @lc code=start
from typing import List


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        ans = [0 for i in range(n)]
        stack = [] # 存储下标
        for index in range(n):
            while stack and temperatures[stack[-1]] < temperatures[index]:
                preDay = stack.pop()
                ans[preDay] = index - preDay
            stack.append(index)
        return ans
# @lc code=end

