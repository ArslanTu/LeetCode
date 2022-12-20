#
# @lc app=leetcode.cn id=313 lang=python3
#
# [313] 超级丑数
#

# @lc code=start
from heapq import heappop, heappush
from typing import List


class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        hp = [1]
        cnt = 0
        records = set()
        while True:
            cur = heappop(hp)
            cnt += 1
            if cnt == n: return cur
            for factor in primes:
                num = cur * factor
                if num not in records:
                    records.add(num)
                    heappush(hp, num)
# @lc code=end

