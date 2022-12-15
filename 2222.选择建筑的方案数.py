#
# @lc app=leetcode.cn id=2222 lang=python3
#
# [2222] 选择建筑的方案数
#

# @lc code=start
class Solution:
    def numberOfWays(self, s: str) -> int:
        n = len(s)
        nums = [[0, 0] for i in range(n)]
        leftResNum = rightResNum = leftOffNum = rightOffNum = 0
        for i in range(n):
            if s[i] == '0':
                leftOffNum += 1
                nums[i][0] = leftResNum
            else:
                leftResNum += 1
                nums[i][0] = leftOffNum
        for i in range(n - 1, -1, -1):
            if s[i] == '0':
                rightOffNum += 1
                nums[i][1] = rightResNum
            else:
                rightResNum += 1
                nums[i][1] = rightOffNum
        ans = 0
        for i in range(n):
            ans += nums[i][0] * nums[i][1]
        return ans
# @lc code=end

