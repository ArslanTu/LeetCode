#
# @lc app=leetcode.cn id=1094 lang=python3
#
# [1094] 拼车
#

# @lc code=start
from collections import defaultdict
from typing import List


class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        diff = defaultdict(int)
        for trip in trips:
            diff[trip[1]] -= trip[0]
            diff[trip[2]] += trip[0] # 注意这里不是下一个位置，在当前位置就直接下车了
        milestones = sorted(diff.keys())
        for milestone in milestones:
            capacity += diff[milestone]
            if capacity < 0: return False
        return True
# @lc code=end

