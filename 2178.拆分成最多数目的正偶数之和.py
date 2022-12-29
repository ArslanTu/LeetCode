#
# @lc app=leetcode.cn id=2178 lang=python3
#
# [2178] 拆分成最多数目的正偶数之和
#

# @lc code=start
from typing import List


class Solution:
    __nums: List[int]
    __n: int
    # def __init__(self) -> None:
    #     self.__nums = [0]
    #     cur = 1
    #     while self.__nums[cur - 1] < 1e10:
    #         self.__nums.append(self.__nums[cur - 1] + (cur << 1))
    #         cur += 1
    #     self.__n = len(self.__nums)
    #     print(self.__nums)
    def maximumEvenSplit(self, finalSum: int) -> List[int]:
        if (finalSum & 1) == 1: return []
        
        self.__nums = [0]
        cur = 1
        while self.__nums[cur - 1] < finalSum:
            self.__nums.append(self.__nums[cur - 1] + (cur << 1))
            cur += 1
        self.__n = len(self.__nums)
        
        l, r = 0, self.__n - 1
        while l <= r:
            m = (l + r) // 2
            if self.__nums[m] == finalSum:
                r = m
                break
            elif self.__nums[m] > finalSum: r = m - 1
            else: l = m + 1
        ans = []
        for i in range(1, r + 1):
            ans.append(i << 1)
        ans[r - 1] += finalSum - sum(ans)
        return ans

# @lc code=end

sl = Solution()
print(sl.maximumEvenSplit(28))