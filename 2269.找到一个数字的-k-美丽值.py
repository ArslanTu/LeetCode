#
# @lc app=leetcode.cn id=2269 lang=python3
#
# [2269] 找到一个数字的 K 美丽值
#

# @lc code=start
class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        ans = 0
        sNum = str(num)
        for i in range(len(sNum) - k + 1):
            sub = int(sNum[i: k + i])
            if sub != 0 and num % sub == 0: ans += 1
        return ans
# @lc code=end

