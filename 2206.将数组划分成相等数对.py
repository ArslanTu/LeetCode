#
# @lc app=leetcode.cn id=2206 lang=python3
#
# [2206] 将数组划分成相等数对
#

# @lc code=start
from typing import List


class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        cnts = [0 for i in range(501)]
        for num in nums: cnts[num] += 1
        for cnt in cnts:
            if (cnt & 1) != 0: return False
        return True
# @lc code=end

