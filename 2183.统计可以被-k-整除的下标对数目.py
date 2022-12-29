#
# @lc app=leetcode.cn id=2183 lang=python3
#
# [2183] 统计可以被 K 整除的下标对数目
#

# @lc code=start
from typing import List


class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        def getContent(x: int) -> List[int]:
            content = []
            i = 2
            while i * i <= x:
                if (x % i == 0):
                    while x % i == 0:
                        content.append(i)
                        x = x // i
                i += 1
            if x > 1: content.append(x)
            return content

        n = len(nums)
        content = [getContent(nums[i]) for i in range(n)]
# @lc code=end

p1 = [8,10,2,5,9,6,3,8,2]
p2 = 6
sl = Solution()
print(sl.countPairs(p1, p2))