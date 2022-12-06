#
# @lc app=leetcode.cn id=2271 lang=python3
#
# [2271] 毯子覆盖的最多白色砖块数
#
from typing import List
# @lc code=start
class Solution:
    def maximumWhiteTiles(self, tiles: List[List[int]], carpetLen: int) -> int:
        tiles.sort(key = lambda x: x[0])
        cover = ans = left = 0
        for tl, tr in tiles:
            cover += tr - tl + 1
            while tr - tiles[left][1] + 1 > carpetLen:
                cover -= tiles[left][1] - tiles[left][0] +  1
                left += 1
            ans = max(ans, cover - max(tr - tiles[left][0] + 1 - carpetLen, 0))
        return ans
# @lc code=end

