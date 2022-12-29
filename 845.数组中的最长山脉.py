#
# @lc app=leetcode.cn id=845 lang=python3
#
# [845] 数组中的最长山脉
#

# @lc code=start
from typing import List


class Solution:
    def longestMountain(self, arr: List[int]) -> int:
        # ans = 0
        # n = len(arr)
        # cnt = 1
        # down = False
        # for i in range(1, n):
        #     if (not down) and arr[i] > arr[i - 1]: cnt += 1
        #     elif arr[i] < arr[i - 1]:
        #         if cnt > 1:
        #             down = True
        #             cnt += 1
        #         else:
        #             down = False
        #             cnt = 1
        #     elif down and arr[i] > arr[i - 1]:
        #         down = False
        #         ans = ans if ans > cnt else cnt
        #         cnt = 2
        #     elif arr[i] == arr[i - 1]:
        #         if down:
        #             ans = ans if ans > cnt else cnt
        #             down = False
        #         cnt = 1
        # if down: ans = ans if ans > cnt else cnt
        # return ans
        ans = 0
        n = len(arr)
        for i in range(1, n - 1):
            if arr[i - 1] < arr[i] and arr[i + 1] < arr[i]:
                cnt = 1
                for j in range(i - 1, -1, -1):
                    if arr[j] < arr[j + 1]: cnt += 1
                    else: break
                for k in range(i + 1, n):
                    if arr[k] < arr[k - 1]: cnt += 1
                    else: break
                ans = ans if ans > cnt else cnt
        return ans
# @lc code=end

