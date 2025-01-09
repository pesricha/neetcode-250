from typing import List

class LinkedList:
    def __init__(self):
        self.head = None
    
    def insert_at_begin(self, userId, tweetId):
        new_node = Node(userId=userId, tweetId=tweetId)
        new_node.next = self.head
        self.head = new_node
    

class Node:
    def __init__(self, userId, tweetId):
        self.userId = userId
        self.tweetId = tweetId
        self.next = None


class Twitter:

    def __init__(self):
        self.follower_to_following = dict()
        self.user_tweets_ll = LinkedList()
        self.time = 1

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.user_tweets_ll.insert_at_begin(userId=userId, tweetId=tweetId)
        if userId not in self.follower_to_following:
            self.follower_to_following[userId] = set()
            self.follower_to_following[userId].add(userId)
        

    def getNewsFeed(self, userId: int) -> List[int]:
        if userId not in self.follower_to_following:
            self.follower_to_following[userId] = set()
            self.follower_to_following[userId].add(userId)
        tweet_list = list()
        iterator = self.user_tweets_ll.head
        counter = 10
        while iterator and counter:
            if iterator.userId in self.follower_to_following[userId]:
                tweet_list.append(iterator.tweetId)
                counter -= 1
            iterator = iterator.next
        
        return tweet_list


    def follow(self, followerId: int, followeeId: int) -> None:
        if followerId not in self.follower_to_following:
            self.follower_to_following[followerId] = set()
            self.follower_to_following[followerId].add(followerId)
        self.follower_to_following[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followeeId in self.follower_to_following[followerId]:
            self.follower_to_following[followerId].remove(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)