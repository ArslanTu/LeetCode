#
# @lc app=leetcode.cn id=918 lang=python3
#
# [918] 环形子数组的最大和
#

# @lc code=start
from typing import List


# class Solution:
#     def maxSubarraySumCircular(self, nums: List[int]) -> int:
#         n = len(nums)
#         nums = nums * 2
#         sum = 0
#         cnt = 0
#         cur = []
#         maxSum = nums[0]
#         for num in nums:
#             sum += num
#             cnt += 1
#             cur.append(num)
#             maxSum = maxSum if maxSum > sum else sum
#             if sum <= 0:
#                 sum = 0
#                 cnt = 0
#                 cur = []
#             if cnt == n:
#                 sum -= cur[0]
#                 cnt -= 1
#                 cur.pop(0)
#                 while cur and cur[0] <= 0:
#                     sum -= cur[0]
#                     cnt -= 1
#                     cur.pop(0)
#                 maxSum = maxSum if maxSum > sum else sum
#         return maxSum

class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        maxSum = minSum = nums[0]
        n = len(nums)
        sumMax = sumMin = 0
        i = 0
        for num in nums:
            sumMax += num
            maxSum = maxSum if maxSum > sumMax else sumMax
            if sumMax <= 0:
                sumMax = 0
            
            sumMin += num
            minSum = minSum if minSum < sumMin else sumMin
            if i < n - 1 and sumMin >= nums[i + 1]: sumMin = 0
        total = sum(nums)
        return max(maxSum, total - minSum)
# @lc code=end

