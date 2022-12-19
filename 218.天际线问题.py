#
# @lc app=leetcode.cn id=218 lang=python3
#
# [218] 天际线问题
#

# @lc code=start
from typing import List


class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        buildings.sort(key = lambda building: building[2], reverse = True)
        buildings.sort(key = lambda building: building[0])
        ans = [[buildings[0], buildings[2]]]
        n = len(buildings)
        for i in range(1, n):
            
# @lc code=end

