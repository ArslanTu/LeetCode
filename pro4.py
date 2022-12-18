from math import log2
from typing import List


class Solution:
	def cycleLengthQueries(self, n: int, queries: List[List[int]]) -> List[int]:
		m = len(queries)
		ans = [0 for i in range(m)]
		for i in range(m):
			h1 = h2 = 0
			q1, q2 = queries[i][0], queries[i][1]
			while q1 != q2:
				if q1 > q2:
					q1 //= 2
					h1 += 1
				else:
					q2 //= 2
					h2 += 1
			ans[i] = h1 + h2 + 1
		return ans