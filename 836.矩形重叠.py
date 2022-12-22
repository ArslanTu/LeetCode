#
# @lc app=leetcode.cn id=836 lang=python3
#
# [836] 矩形重叠
#

# @lc code=start
from typing import List


class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        x1, y1, x2, y2 = 0, 1, 2, 3
        if rec2[x1] < rec1[x1]:
            temp = rec1
            rec1 = rec2
            rec2 = temp
        if rec1[x2] > rec2[x1] and rec1[y2] > rec2[y1] and rec1[y1] < rec2[y2]: return True
        return False
# @lc code=end

