#
# @lc app=leetcode.cn id=204 lang=python3
#
# [204] 计数质数
#

# @lc code=start
from math import sqrt


class Solution:
    def countPrimes(self, n: int) -> int:
        if n <= 2:  return 0
        nums = [1 for i in range(n + 1)]
        nums[0] = 0
        nums[1] = 0
        for num in range(2, int(sqrt(n)) + 1):
            if nums[num]:
                for i in range(num * num, n + 1, num):
                    nums[i] = 0
        return sum(nums[:n])
# @lc code=end

sl = Solution()
print(sl.countPrimes(3))