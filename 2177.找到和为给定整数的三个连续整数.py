#
# @lc app=leetcode.cn id=2177 lang=python3
#
# [2177] 找到和为给定整数的三个连续整数
#

# @lc code=start
from typing import List


class Solution:
    def sumOfThree(self, num: int) -> List[int]:
        if num % 3 != 0: return []
        return [(num // 3) - 1,num // 3 , (num // 3) + 1]
# @lc code=end

