#
# @lc app=leetcode.cn id=789 lang=python3
#
# [789] 逃脱阻碍者
#

# @lc code=start
from heapq import heappush
from typing import List


class Solution:
    def escapeGhosts(self, ghosts: List[List[int]], target: List[int]) -> bool:
        limit = abs(target[0]) + abs(target[1])
        for enemy in ghosts:
            if abs(enemy[0] - target[0]) + abs(enemy[1] - target[1]) <= limit: return False
        return True
# @lc code=end

