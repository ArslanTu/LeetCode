#
# @lc app=leetcode.cn id=2286 lang=python3
#
# [2286] 以组为单位订音乐会的门票
#
from typing import List
# @lc code=start
class BookMyShow:
    seat = []
    colUpBound = 0
    rowUpBound = 0
    start = 0
    
    def __init__(self, n: int, m: int):
        self.seat = [0] * n
        self.colUpBound = m
        self.rowUpBound = n
        self.start = 0

    def gather(self, k: int, maxRow: int) -> List[int]:
        for i in range(self.start, self.rowUpBound):
            if i <= maxRow:
                if self.colUpBound - self.seat[i] >= k:
                    ans = [i, self.seat[i]]
                    self.seat[i] += k
                    while self.start < self.rowUpBound and self.seat[self.start] == self.colUpBound: self.start += 1
                    return ans
        return []


    def scatter(self, k: int, maxRow: int) -> bool:
        seatBackup = list(self.seat)
        startBackup = self.start
        for i in range(self.start, self.rowUpBound):
            if i <= maxRow:
                if self.seat[i] < self.colUpBound:
                    if (k <= self.colUpBound - self.seat[i]):
                        self.seat[i] += k
                        while self.start < self.rowUpBound and self.seat[self.start] == self.colUpBound: self.start += 1
                        return True
                    else:
                        k -= self.colUpBound - self.seat[i]
                        self.seat[i] = self.colUpBound
                        while self.start < self.rowUpBound and self.seat[self.start] == self.colUpBound: self.start += 1
            else: break
        self.seat = seatBackup
        self.start = startBackup
        return False



# Your BookMyShow object will be instantiated and called as such:
# obj = BookMyShow(n, m)
# param_1 = obj.gather(k,maxRow)
# param_2 = obj.scatter(k,maxRow)
# @lc code=end

