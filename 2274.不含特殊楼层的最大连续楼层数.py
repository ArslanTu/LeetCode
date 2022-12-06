#
# @lc app=leetcode.cn id=2274 lang=python3
#
# [2274] 不含特殊楼层的最大连续楼层数
#
from typing import List
# @lc code=start
class Solution:
    def maxConsecutive(self, bottom: int, top: int, special: List[int]) -> int:
        n = len(special)
        special.sort()
        ans = special[0] - bottom
        for i in range(1, n):
            ans = max(ans, special[i] - special[i - 1] - 1)
        ans = max(ans, top - special[n - 1])
        return ans
# @lc code=end

