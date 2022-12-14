#
# @lc app=leetcode.cn id=2224 lang=python3
#
# [2224] 转化时间需要的最少操作数
#

# @lc code=start
class Solution:
    def convertTime(self, current: str, correct: str) -> int:
        ans = int(correct[0:2]) - int(current[0:2])
        diff = int(correct[3:5]) - int(current[3:5])
        if diff < 0:
            diff += 60
            ans -= 1
        while diff:
            if diff >= 15:
                cnt = int(diff / 15)
                diff -= cnt * 15
                ans += cnt
            elif diff >= 5:
                cnt = int(diff / 5)
                diff -= cnt * 5
                ans += cnt
            else:
                ans += diff
                diff = 0
        return ans
# @lc code=end

