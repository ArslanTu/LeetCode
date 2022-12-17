#
# @lc app=leetcode.cn id=1854 lang=python3
#
# [1854] 人口最多的年份
#

# @lc code=start
from collections import defaultdict
from typing import List


class Solution:
    def maximumPopulation(self, logs: List[List[int]]) -> int:
        diff = defaultdict(int)
        for log in logs:
            diff[log[0]] += 1
            diff[log[1]] -= 1
        times = sorted(diff.keys())
        maxNum = ans = sum = 0
        for time in times:
            sum += diff[time]
            if sum > maxNum:
                maxNum = sum
                ans = time
        return ans
# @lc code=end

