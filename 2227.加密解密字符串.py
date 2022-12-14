#
# @lc app=leetcode.cn id=2227 lang=python3
#
# [2227] 加密解密字符串
#

# @lc code=start
from typing import List


class Encrypter:
    __en = {}
    __dictionary = {}
    def __init__(self, keys: List[str], values: List[str], dictionary: List[str]):
        self.__en = {}
        self.__dictionary = {}
        n = len(keys)
        for i in range(n):
            self.__en[keys[i]] = values[i]
        for word in dictionary:
            s = self.encrypt(word)
            if s not in self.__dictionary: self.__dictionary[s] = 1
            else: self.__dictionary[s] += 1
    def encrypt(self, word1: str) -> str:
        res = ""
        for ch in word1:
            if ch not in self.__en: return ""
            res += self.__en[ch]
        return res


    def decrypt(self, word2: str) -> int:
        if word2 not in self.__dictionary: return 0
        else: return self.__dictionary[word2]



# Your Encrypter object will be instantiated and called as such:
# obj = Encrypter(keys, values, dictionary)
# param_1 = obj.encrypt(word1)
# param_2 = obj.decrypt(word2)
# @lc code=end

