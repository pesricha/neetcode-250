#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int userId;
    int tweetId;
    Node* next;
    Node(int uId, int tId) : userId(uId), tweetId(tId), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {};

    void insertAtBegin(int userId, int tweetId) {
        Node * newNode = new Node(userId, tweetId);
        newNode->next = this->head;
        this->head = newNode;
    }
};

class Twitter {
public:

    unordered_map<int, set<int>> followerToFollowing;
    LinkedList userTweetsLL;
    int time = 1;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        userTweetsLL.insertAtBegin(userId, tweetId);
        if (followerToFollowing.find(userId) == followerToFollowing.end()){
            followerToFollowing[userId] = set<int>();
            followerToFollowing[userId].insert(userId);
        }
    }
    
    vector<int> getNewsFeed(int userId) {
         if (followerToFollowing.find(userId) == followerToFollowing.end()){
            followerToFollowing[userId] = set<int>();
            followerToFollowing[userId].insert(userId);
        }
        vector<int> tweetList;
        Node* iterator = userTweetsLL.head;
        int counter = 10;
        while (iterator && counter) {
            if (
                followerToFollowing[userId].find(iterator->userId) 
                != followerToFollowing[userId].end() 
            ) {
                tweetList.push_back(iterator->tweetId);
                counter--;
            }
            iterator = iterator->next;
        }
        return tweetList;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerToFollowing.find(followerId) == followerToFollowing.end()){
            followerToFollowing[followerId] = set<int>();
            followerToFollowing[followerId].insert(followerId);
        }
        followerToFollowing[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerToFollowing[followerId].find(followeeId) 
        != followerToFollowing[followerId].end()) {
            followerToFollowing[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */