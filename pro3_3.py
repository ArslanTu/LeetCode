from typing import List


class Solution:
	def isPossible(self, n: int, edges: List[List[int]]) -> bool:
		odd_count = 0
		for i in range(1, n+1):
			degree = 0
			for a, b in edges:
				if a == i or b == i:
					degree += 1
			if degree % 2 == 1:
				odd_count += 1

		return odd_count in [0, 1, 2]