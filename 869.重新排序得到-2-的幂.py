#
# @lc app=leetcode.cn id=869 lang=python3
#
# [869] 重新排序得到 2 的幂
#

# @lc code=start
from cmath import log
from collections import defaultdict


class Solution:
    def __init__(self):
        self.dicts = [defaultdict(int) for i in range(30)]
        for i in range(30):
            num = 1 << i
            while num:
                self.dicts[i][num % 10] += 1
                num //= 10
        print(self.dicts)
    def reorderedPowerOf2(self, n: int) -> bool:
        dic = defaultdict(int)
        while n:
            dic[n % 10] += 1
            n //= 10
        return dic in self.dicts
# @lc code=end

sl = Solution()
print(sl.reorderedPowerOf2(2014))