#
# @lc app=leetcode.cn id=2194 lang=python3
#
# [2194] Excel 表中某个范围内的单元格
#

# @lc code=start
from typing import List


class Solution:
    def cellsInRange(self, s: str) -> List[str]:
        ans = []
        for c in range(ord(s[0]), ord(s[3]) + 1):
            for j in range(int(s[1]), int(s[4]) + 1):
                ans.append(chr(c) + str(j))
        return ans
# @lc code=end

