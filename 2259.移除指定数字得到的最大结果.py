#
# @lc app=leetcode.cn id=2259 lang=python3
#
# [2259] 移除指定数字得到的最大结果
#

# @lc code=start
class Solution:
    def removeDigit(self, number: str, digit: str) -> str:
        n = len(number)
        last = -1
        for i in range(n):
            if number[i] == digit:
                last = i
                if (i == n - 1 or number[i] < number[i + 1]): break
        return number[0:last] + number[last + 1:]
# @lc code=end

