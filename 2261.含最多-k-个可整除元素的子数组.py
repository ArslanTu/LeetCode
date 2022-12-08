#
# @lc app=leetcode.cn id=2261 lang=python3
#
# [2261] 含最多 K 个可整除元素的子数组
#

# @lc code=start
from typing import List


class Solution:
    def countDistinct(self, nums: List[int], k: int, p: int) -> int:
        n = len(nums)
        cnt = [[0] * n] * n
        ans = {}
        for i in range(n):
            if nums[i] % p == 0: cnt[i][i] = 1
            for j in range(i + 1, n):
                if nums[j] % p == 0: cnt[i][j] = cnt[i][j - 1] + 1
                if cnt[i][j] <= k: 
                    ans[nums[i:j + 1]] = 1
                else: break
        return len(ans)
# @lc code=end

