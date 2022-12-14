#
# @lc app=leetcode.cn id=2226 lang=python3
#
# [2226] 每个小孩最多能分到多少糖果
#

# @lc code=start
from typing import List


class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        total = sum(candies)
        if total < k: return 0
        elif total == k: return 1
        low, high = 1, max(candies)
        ans = 0
        while low <= high:
            mid = low + int((high - low) / 2)
            cnt = 0
            for candy in candies:
                cnt += int(candy / mid)
            if cnt >= k:
                ans = mid
                low = mid + 1
            else: high = mid - 1
        return ans
# @lc code=end

