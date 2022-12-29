#
# @lc app=leetcode.cn id=828 lang=python3
#
# [828] 统计子串中的唯一字符
#

# @lc code=start
class Solution:
    def uniqueLetterString(self, s: str) -> int:
        ans = 0
        n = len(s)
        c = [[] for i in range(26)]
        for i in range(n):
            c[ord(s[i]) - ord('A')].append(i)
        for i in range(26):
            if c[i] == []: continue # 字符不存在，跳过
            elif len(c[i]) == 1: # 字符唯一，贡献等于所有包含了它的子串数
                ans += (c[i][0] + 1) * (n - c[i][0])
            else: # 字符不唯一，分三种情况讨论，字符前无相同字符；字符两边都有相同字符；字符后无相同字符
                for j in range(len(c[i])):
                    if j == 0:
                        ans += (c[i][j] + 1) * (c[i][j + 1] - c[i][j])
                    elif j < len(c[i]) - 1:
                        ans += (c[i][j] - c[i][j - 1]) * (c[i][j + 1] - c[i][j])
                    else:
                        ans += (c[i][j] - c[i][j - 1]) * (n - c[i][j])
        return ans
# @lc code=end
sl = Solution()
p1 = "LEETCODE"
print(sl.uniqueLetterString(p1))