#
# @lc app=leetcode.cn id=2257 lang=python3
#
# [2257] 统计网格图中没有被保卫的格子数
#

# @lc code=start
from typing import List


class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        pic = [[0 for i in range(n)] for j in range(m)]
        ans = 0
        for guard in guards: pic[guard[0]][guard[1]] = -1
        for wall in walls: pic[wall[0]][wall[1]] = -1
        for guard in guards:
            # up
            for i in range(guard[0] - 1, -1, -1):
                if pic[i][guard[1]] == -1: break
                elif pic[i][guard[1]] == 0: 
                    pic[i][guard[1]] = 1
                    ans += 1
            # down
            for i in range(guard[0] + 1, m):
                if pic[i][guard[1]] == -1: break
                elif pic[i][guard[1]] == 0: 
                    pic[i][guard[1]] = 1
                    ans += 1
            # left
            for i in range(guard[1] - 1, -1, -1):
                if pic[guard[0]][i] == -1: break
                elif pic[guard[0]][i] == 0: 
                    pic[guard[0]][i] = 1
                    ans += 1
            # right
            for i in range(guard[1] + 1, n):
                if pic[guard[0]][i] == -1: break
                elif pic[guard[0]][i] == 0: 
                    pic[guard[0]][i] = 1
                    ans += 1
        return m * n - ans - len(guards) - len(walls)
# @lc code=end

