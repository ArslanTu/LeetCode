from typing import List


class Solution:
    def countLatticePoints(self, circles: List[List[int]]) -> int:
        ans = set()
        for circle in circles:
            ans.add(str(circle[0]) + str(circle[1]))
            for i in range(1, circle[2] + 1):
                ans.add(str(circle[0]) + str(circle[1] + i))
                ans.add(str(circle[0]) + str(circle[1] - i))
                ans.add(str(circle[0] + i) + str(circle[1]))
                ans.add(str(circle[0] - i) + str(circle[1]))
                if i < circle[2]:
                    ans.add(str(circle[0] + i) + str(circle[1] + i))
                    ans.add(str(circle[0] + i) + str(circle[1] - i))
                    ans.add(str(circle[0] - i) + str(circle[1] - i))
                    ans.add(str(circle[0] - i) + str(circle[1] + i))
        return len(ans)

solution = Solution()
circles = [[8,9,6],[9,8,4],[4,1,1],[8,5,1],[7,1,1],[6,7,5],[7,1,1],[7,1,1],[5,5,3]]
solution.countLatticePoints(circles)