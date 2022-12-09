#
# @lc app=leetcode.cn id=2250 lang=python3
#
# [2250] 统计包含每个点的矩形数目
#

# @lc code=start
from sortedcontainers import SortedList

class Solution:
    def countRectangles(self, rectangles: List[List[int]], points: List[List[int]]) -> List[int]:
        rectangles.sort(key=lambda r: -r[1])
        n = len(points)
        ans = [0] * n
        i, xs = 0, SortedList()
        for (x, y), id in sorted(zip(points, range(n)), key=lambda x: -x[0][1]):
            while i < len(rectangles) and rectangles[i][1] >= y:
                xs.add(rectangles[i][0])
                i += 1
            ans[id] = i - xs.bisect_left(x)
        return ans
# @lc code=end

