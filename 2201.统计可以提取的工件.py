#
# @lc app=leetcode.cn id=2201 lang=python3
#
# [2201] 统计可以提取的工件
#

# @lc code=start
from collections import defaultdict
from typing import List


class Solution:
    def digArtifacts(self, n: int, artifacts: List[List[int]], dig: List[List[int]]) -> int:
        ans = 0
        ground = [[0 for i in range(n)] for j in range(n)]
        for r, c in dig: ground[r][c] = 1
        for r1, c1, r2, c2 in artifacts:
            if r1 == r2 and c1 == c2:
                if ground[r1][c1] == 1:
                    ans += 1
            elif r1 == r2:
                ans += 1
                for j in range(c1, c2 + 1):
                    if ground[r1][j] == 0:
                        ans -= 1
                        break
            elif c1 == c2:
                ans += 1
                for j in range(r1, r2 + 1):
                    if ground[j][c1] == 0:
                        ans -= 1
                        break
            else:
                if ground[r1][c1] == 1 and ground[r1][c2] == 1 and ground[r2][c2] == 1 and ground[r2][c1] == 1:
                    ans += 1
        return ans
# @lc code=end

