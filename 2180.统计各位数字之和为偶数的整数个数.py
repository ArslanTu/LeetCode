#
# @lc app=leetcode.cn id=2180 lang=python3
#
# [2180] 统计各位数字之和为偶数的整数个数
#

# @lc code=start
from typing import List


class Solution:
    def countEven(self, num: int) -> int:
        def isEven(x: int) -> bool:
            sum = 0
            while x:
                sum += x % 10
                x //= 10
            return (sum & 1) == 0
        return sum(isEven(i) for i in range(1, num + 1))
# @lc code=end

