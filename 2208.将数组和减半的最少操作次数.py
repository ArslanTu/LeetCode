#
# @lc app=leetcode.cn id=2208 lang=python3
#
# [2208] 将数组和减半的最少操作次数
#

# @lc code=start
from heapq import heappop, heappush
from typing import List


class Solution:
    def halveArray(self, nums: List[int]) -> int:
        ans = 0
        hp = []
        total = sum(nums)
        cur = total
        target = total / 2
        for num in nums:
            heappush(hp, -num)
        while cur > target:
            num = -heappop(hp)
            num /= 2
            cur -= num
            heappush(hp, -num)
            ans += 1
        return ans
# @lc code=end

