#
# @lc app=leetcode.cn id=2011 lang=python3
#
# [2011] 执行操作后的变量值
#

# @lc code=start
from typing import List


class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        ans = 0
        for op in operations:
            if op == "++X" or op == "X++": ans += 1
            else: ans -= 1
        return ans
# @lc code=end

