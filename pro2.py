from typing import List


class Solution:
    def smallestValue(self, n: int) -> int:
        def getContent(x: int) -> List[int]:
            content = []
            i = 2
            while i * i <= x:
                if (x % i == 0):
                    while x % i == 0:
                        content.append(i)
                        x = x // i
                i += 1
            if x > 1: content.append(x)
            return content
        c = getContent(n)
        while len(c) != 1:
            n = sum(c)
            c = getContent(n)
            if n == sum(c): return n
        return c[0]
solution = Solution()
x = solution.smallestValue(4)
y = 1