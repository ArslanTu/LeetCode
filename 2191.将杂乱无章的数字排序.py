#
# @lc app=leetcode.cn id=2191 lang=python3
#
# [2191] 将杂乱无章的数字排序
#

# @lc code=start
from typing import List


class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        def trans(x: int) -> int:
            if x == 0: return mapping[0]
            res = 0
            i = 0
            while x:
                res += mapping[(x % 10)] * pow(10, i)
                x //= 10
                i += 1
            return res
        return sorted(nums, key = lambda x: trans(x))
# @lc code=end

sl = Solution()
p1 = [9,8,7,6,5,4,3,2,1,0]
p2 = [0,1,2,3,4,5,6,7,8,9]
sl.sortJumbled(p1, p2)