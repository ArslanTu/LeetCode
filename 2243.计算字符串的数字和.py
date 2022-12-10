#
# @lc app=leetcode.cn id=2243 lang=python3
#
# [2243] 计算字符串的数字和
#

# @lc code=start
class Solution:
    def digitSum(self, s: str, k: int) -> str:
        while(len(s) > k):
            t = ""
            sum = 0
            for i in range(len(s)):
                sum += int(s[i])
                if i == len(s) - 1 or (i + 1) % k == 0:
                    t += str(sum)
                    sum = 0
            s = t
        return s
# @lc code=end

