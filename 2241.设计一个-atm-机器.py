#
# @lc app=leetcode.cn id=2241 lang=python3
#
# [2241] 设计一个 ATM 机器
#

# @lc code=start
from typing import List


class ATM:
    account = []
    money = [20, 50, 100, 200, 500]
    n = len(money)
    def __init__(self):
        self.account = [0 for i in range(self.n)]

    def deposit(self, banknotesCount: List[int]) -> None:
        for i in range(self.n):
            self.account[i] += banknotesCount[i]

    def withdraw(self, amount: int) -> List[int]:
        backAccount = list(self.account)
        res = [0 for i in range(self.n)]
        flag = True
        while amount > 0 and flag:
            for i in range(self.n - 1, -1, -1):
                if amount >= self.money[i] and self.account[i] > 0:
                    cnt = min(int(amount / self.money[i]), self.account[i])
                    res[i] += cnt
                    self.account[i] -= cnt
                    amount -= self.money[i] * cnt
                    break
                if i == 0: flag = False
        if amount > 0:
            self.account = backAccount
            return [-1]
        else: return res


# Your ATM object will be instantiated and called as such:
# obj = ATM()
# obj.deposit(banknotesCount)
# param_2 = obj.withdraw(amount)
# @lc code=end

