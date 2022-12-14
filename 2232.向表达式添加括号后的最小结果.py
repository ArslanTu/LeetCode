#
# @lc app=leetcode.cn id=2232 lang=python3
#
# [2232] 向表达式添加括号后的最小结果
#

# @lc code=start
from cmath import inf


class Solution:
    def minimizeResult(self, expression: str) -> str:
        plusPos = expression.find("+")
        num_1 = expression[0: plusPos]
        num_2 = expression[plusPos + 1: len(expression)]
        m = len(num_1)
        n = len(num_2)
        ans = int(num_1) + int(num_2)
        lc = 0
        rc = 0
        for i in range(m):
            leftMul = int(num_1[0: i]) if num_1[0: i] != '' else 1
            leftSum = int(num_1[i: m])
            for j in range(n):
                rightMulti = int(num_2[n - j: n]) if num_2[n - j: n] != '' else 1
                rightSum = int(num_2[0: n - j])
                cur = (leftSum + rightSum) * leftMul * rightMulti
                if cur < ans:
                    ans, lc, rc = cur, i, j
        ans = num_1[0: lc] + "(" + num_1[lc: m] + "+" + num_2[0: n - rc] + ")" + num_2[n - rc: n]
        return ans
# @lc code=end

