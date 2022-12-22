#
# @lc app=leetcode.cn id=2217 lang=python3
#
# [2217] 找到指定长度的回文数
#

# @lc code=start
from typing import List


class Solution:
    def kthPalindrome(self, queries: List[int], intLength: int) -> List[int]:
        n = len(queries)
        ans = [-1 for i in range(n)]
        queries = sorted(zip(queries, range(n)))
        isEven = True
        length = intLength >> 1
        if (intLength & 1) == 1:
            length += 1
            isEven = False
        length -= 1
        baseNum = 10 ** length
        limit = baseNum * 10
        i = 0
        while i < n:
            num = baseNum + queries[i][0] - 1
            if num >= limit: break
            # 偶数长度
            if isEven:
                ans[queries[i][1]] = int(str(num) + str(num)[::-1])
            # 奇数长度
            else:
                ans[queries[i][1]] = int(str(num // 10) + str(num)[::-1])
            i += 1
            while i < n and queries[i][0] == queries[i - 1][0]:
                ans[queries[i][1]] = ans[queries[i - 1][1]]
                i += 1
        return ans
# @lc code=end

