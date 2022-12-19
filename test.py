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
        tweets = list(self.__tweets[userId])
        for followee in self.__followed[userId]:
            curTweets = nlargest(10, self.__tweets[followee])
            for tweet in curTweets: heappush(tweets, tweet)
        newTweets = nlargest(10, tweets)
        ans = []
        while newTweets:
            ans.append(heappop(newTweets)[1])
        return ans

    def follow(self, followerId: int, followeeId: int) -> None:
        self.__followed[followerId].add(followeeId)
        print()

    def unfollow(self, followerId: int, followeeId: int) -> None:
        self.__followed[followerId].discard(followeeId)
        print()


twitter = Twitter()
twitter.postTweet(1, 5)
twitter.getNewsFeed(1)
twitter.follow(1, 2)
twitter.postTweet(2, 6)
twitter.getNewsFeed(1)
twitter.unfollow(1, 2)
twitter.getNewsFeed(1)
