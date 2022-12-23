#
# @lc app=leetcode.cn id=2211 lang=python3
#
# [2211] 统计道路上的碰撞次数
#

# @lc code=start
class Solution:
    def countCollisions(self, directions: str) -> int:
        # old = ""
        # new = directions
        # while old != new:
        #     old = new
        #     new = new.replace("RL", "S")
        # old = ""
        # while old != new:
        #     old = new
        #     new = new.replace("RS", "S")
        # old = ""
        # while old != new:
        #     old = new
        #     new = new.replace("SL", "S")
        # origin = directions.count("L") + directions.count("R")
        # now = new.count("L") + new.count("R")
        # return origin - now
        n = len(directions)
        ans = 0
        total = directions.count("L") + directions.count("R")
        for i in range(n):
            if directions[i] == "L": ans += 1
            else: break
        for i in range(n - 1, -1, -1):
            if directions[i] == "R": ans += 1
            else: break
        return total - ans
# @lc code=end

