from typing import List


class Encrypter:
    __en = {}
    __dictionary = {}
    def __init__(self, keys: List[str], values: List[str], dictionary: List[str]):
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
            res += self.__en[ch]
        return res


    def decrypt(self, word2: str) -> int:
        return self.__dictionary[word2]
en = Encrypter(["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"],["ei","zf","ei","am","gb","zz","zz","ac","qa","mn","aa","is","aa","op","pq","qr","rs","st","tu","uv","aa","sz","bb","aa","ac","aa"],["abcd","acbd","adbc","badc","dacb","cadb","cbda","abad"])
en.encrypt("abce")
en.decrypt("eizfeiam")
