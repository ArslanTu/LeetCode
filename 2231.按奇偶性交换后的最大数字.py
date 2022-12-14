#
# @lc app=leetcode.cn id=2231 lang=python3
#
# [2231] 按奇偶性交换后的最大数字
#

# @lc code=start
class Solution:
    def largestInteger(self, num: int) -> int:
        odd = []
        even = []
        flag = []
        while num > 0:
            cur = num % 10
            num = int(num / 10)
            if (cur & 1) == 0:
                even.append(cur)
                flag.insert(0, 0)
            else:
                odd.append(cur)
                flag.insert(0, 1)
        odd.sort(reverse=True)
        even.sort(reverse=True)
        i = 0
        j = 0
        for k in range(len(flag)):
            if flag[k] == 0:
                num = num * 10 + even[i]
                i += 1
            else:
                num = num * 10 + odd[j]
                j += 1
        return num
# @lc code=end

