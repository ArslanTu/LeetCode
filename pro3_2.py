from collections import defaultdict
from typing import List


class Solution:
	def isPossible(self, n: int, edges: List[List[int]]) -> bool:
		# 构建图
		pic = defaultdict(list)
		for u, v in edges:
			pic = defaultdict(list)
		for u, v in edges:
			pic[u].append(v)
			pic[v].append(u)

		# 使用染色法，对图进行染色
		colors = {}
		def dfs(node, color):
			if node in colors:
				return colors[node] == color
			colors[node] = color
			for neighbor in pic[node]:
				if not dfs(neighbor, 1 - color):
					return False
			return True

		# 如果图是二分图，返回 true
		for node in range(1, n+1):
			if node not in colors:
				if not dfs(node, 0):
					break
		else:
			return True

		# 如果图不是二分图，尝试添加一条边
		for i in range(n):
			for j in range(i+1, n):
				if i+1 not in pic[j+1] and j+1 not in pic[i+1]:
					pic[i+1].append(j+1)
					pic[j+1].append(i+1)
					colors = {}
					for node in range(1, n+1):
						if node not in colors:
							if not dfs(node, 0):
								break
					else:
						return True
					pic[i+1].pop()
					pic[j+1].pop()

		# 如果图还不是二分图，尝试添加第二条边
		for i in range(n):
			for j in range(i+1, n):
				if i+1 not in pic[j+1] and j+1 not in pic[i+1]:
					pic[i+1].append(j+1)
					pic[j+1].append(i+1)
					for k in range(n):
						for l in range(k+1, n):
							if k+1 not in pic[l+1] and l+1 not in pic[k+1]:
								pic[k+1].append(l+1)
								pic[l+1].append(k+1)
								colors = {}
								for node in range(1, n+1):
									if node not in colors:
										if not dfs(node, 0):
											break
								else:
									return True
								pic[k+1].pop()
								pic[l+1].pop()
					pic[i+1].pop()
					pic[j+1].pop()

		# 如果添加两条边都不能使图变成二分图，返回 false
		return False
