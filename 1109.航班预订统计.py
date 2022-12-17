#
# @lc app=leetcode.cn id=1109 lang=python3
#
# [1109] 航班预订统计
#

# @lc code=start
from typing import List


class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        diff = [0 for i in range(n + 2)]
        for book in bookings:
            diff[book[0]] += book[2]
            diff[book[1] + 1] -= book[2]
        ans = [0 for i in range(n)]
        sum = 0
        for i in range(n):
            sum += diff[i + 1]
            ans[i] = sum
        return ans
# @lc code=end

