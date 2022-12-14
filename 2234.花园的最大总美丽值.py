#
# @lc app=leetcode.cn id=2234 lang=python3
#
# [2234] 花园的最大总美丽值
#

# @lc code=start
from typing import List


class Solution:
    def maximumBeauty(self, flowers: List[int], newFlowers: int, target: int, full: int, partial: int) -> int:
        flowers.sort(reverse = True)
        n = len(flowers)
 
# @lc code=end

