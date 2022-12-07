#
# @lc app=leetcode.cn id=2264 lang=python3
#
# [2264] 字符串中最大的 3 位相同数字
#

# @lc code=start
class Solution:
    def largestGoodInteger(self, num: str) -> str:
        n = len(num)
        ans = ""
        for i in range(2, n):
            if num[i] == num[i - 1] and num[i] == num[i - 2]:
                if num[i - 2:i + 1] > ans: ans = num[i - 2:i + 1]
        return ans
# @lc code=end

