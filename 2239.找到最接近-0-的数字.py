#
# @lc app=leetcode.cn id=2239 lang=python3
#
# [2239] 找到最接近 0 的数字
#

# @lc code=start
from cmath import inf
from typing import List


class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        ans = inf
        for num in nums:
            if abs(num) < abs(ans): ans = num
            elif abs(num) == abs(ans): ans = ans if ans > num else num
        return ans
# @lc code=end

