#
# @lc app=leetcode.cn id=264 lang=python3
#
# [264] 丑数 II
#

# @lc code=start
from heapq import heappop, heappush


class Solution:
	def nthUglyNumber(self, n: int) -> int:
		hp = [1]
		cnt = 0
		factors = [2, 3, 5]
		records = set()
		while True:
			cur = heappop(hp)
			cnt += 1
			if cnt == n: return cur
			for factor in factors:
				if (cur * factor) not in records:
					heappush(hp, cur * factor)
					records.add(cur * factor)
# @lc code=end

