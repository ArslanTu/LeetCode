# from tracemalloc import start
# from typing import List


# class Solution:
#     def longestRepeating(self, s: str, queryCharacters: str, queryIndices: List[int]) -> List[int]:
#         maxLen = 1
#         maxPa = [0, 0]
#         n = len(s)

#         def compute(t: str, len: int) -> List[int]:
#             res = [0, 0, 1] # start, end, len
#             start = end = 0
#             cnt = 1
#             for i in range(1, len):
#                 if t[i] == t[i - 1]:
#                     cnt += 1
#                     end += 1
#                     if cnt > res[2]:
#                         res[0] = start
#                         res[1] = end
#                         res[2] = cnt
#                 else:
#                     start = i
#                     end = i
#                     cnt = 1
#             return res

#         init = compute(s, n)
#         maxLen = init[2]
#         maxPa[0] = init[0]
#         maxPa[1] = init[1]

#         m = len(queryCharacters)
#         ans = [1 for i in range(m)]
#         for i in range(m):
#             s = s[:queryIndices[i]:] + queryCharacters[i] + s[queryIndices[i] + 1::]
#             if (queryIndices[i] >= maxPa[0]) and (queryIndices[i] <= maxPa[1]):
#                 newRes = compute(s, n)
#                 maxLen = newRes[2]
#                 maxPa[0] = newRes[0]
#                 maxPa[1] = newRes[1]
#                 ans[i] = maxLen
#             else:
#                 cnt = 1
#                 start = end = i
#                 if i > 0:
#                     for j in range(i - 1, -1, -1):
#                         if j >= 0 and s[j] == s[i]:
#                             cnt += 1
#                             start -= 1
#                         else: break
#                 if k < n - 1:
#                     for k in range(i + 1, n):
#                         if k < n and s[k] == s[i]:
#                             cnt += 1
#                             end += 1
#                         else: break
#                 if cnt > maxLen:
#                     maxLen = cnt
#                     maxPa[0] = start
#                     maxPa[1] = end
#                 ans[i] = maxLen
#         return ans
    
# solution = Solution()
# p1 = "mm"
# p2 = "bfviuwsr"
# p3 = [0,0,1,0,0,1,1,0]
# solution.longestRepeating(p1, p2, p3)

for i in range(-1, -1, -1):
    print("111")