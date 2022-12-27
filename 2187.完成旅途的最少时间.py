#
# @lc app=leetcode.cn id=2187 lang=python3
#
# [2187] 完成旅途的最少时间
#

# @lc code=start
from typing import List


class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        l, r = 1, totalTrips * max(time)
        ans = r
        while l <= r:
            m = (l + r) // 2
            if sum(m // t for t in time) >= totalTrips:
                ans = ans if ans < m else m
                r = m - 1
            else: l = m + 1
        return ans
# @lc code=end

