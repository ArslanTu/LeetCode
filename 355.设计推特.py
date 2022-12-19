#
# @lc app=leetcode.cn id=355 lang=python3
#
# [355] 设计推特
#

# @lc code=start
from collections import defaultdict
from heapq import heappop, heappush, nlargest
from typing import List, Set

class Twitter:
    __time: int
    # 每个用户一个堆保存前十条推文
    __tweets: List[List[int]]
    # 每个用户一个集合保存关注用户
    __followed: List[Set[int]]
    def __init__(self):
        self.__time = 0
        self.__tweets = [[] for i in range(501)]
        self.__followed = [set() for i in range(501)]

    def postTweet(self, userId: int, tweetId: int) -> None:
        tweet = [self.__time, tweetId]
        self.__time += 1
        heappush(self.__tweets[userId], tweet)
        while len(self.__tweets[userId]) > 10: heappop(self.__tweets[userId])

    def getNewsFeed(self, userId: int) -> List[int]:
        tweets = nlargest(10, self.__tweets[userId])
        for followee in self.__followed[userId]:
            curTweets = nlargest(10, self.__tweets[followee])
            for tweet in curTweets: heappush(tweets, tweet)
        newTweets = nlargest(10, tweets)
        ans = [newTweets[i][1] for i in range(len(newTweets))]
        return ans

    def follow(self, followerId: int, followeeId: int) -> None:
        self.__followed[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        self.__followed[followerId].discard(followeeId)



# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
# @lc code=end

