// Design Twitter

// Problem Statement: Create a simplified version of a social media platform similar to Twitter. Users should be able to post tweets, follow or unfollow other users, and view the 10 most recent tweets in their news feed.
// Implement the Twitter class as follows:
// Twitter(): Initializes the Twitter object.
// void postTweet(int userId, int tweetId): Composes a new tweet with ID tweetId by the user userId. All tweetIds will be unique.
// List<Integer> getNewsFeed(int userId): Retrieves the 10 most recent tweet IDs in the user's news feed. The news feed should only show posts from users the user follows or from the user themself, with tweets arranged from most recent to least recent.
// void follow(int followerId, int followeeId): The user with ID followerId started following the user with ID followeeId. Input will be given such that followerId is not already following followeeId at the time of function call.
// void unfollow(int followerId, int followeeId): The user with ID followerId unfollowed the user with ID followeeId. Input will be given such that followerId is following followeeId at the time of function call.

// Examples
// Input: [postTweet(1, 2), postTweet(2, 6), getNewsFeed(1), follow(1, 2), getNewsFeed(1), unfollow(1, 2), postTweet(1,7), getNewsFeed(1)]
// Output: [null, null, [2], null, [6, 2], null, [7, 2]]
// Explanation:postTweet(1, 2): User with userId 1 posts tweet with tweetId 2.
// postTweet(2, 6): User with userId 2 posts tweet with tweetId 6.
// getNewsFeed(1): Outputs feed of userId 1 = [2].
// follow(1, 2): User with userId 1 follows user with userId 2.
// getNewsFeed(1): Outputs feed of userId 1 = [6, 2], it contains the news of userId 2 as well.
// unfollow(1, 2): User with userId 1 unfollows user with userId 2.
// postTweet(1,7): User with userId 1 posts tweet with tweetId 7.
// getNewsFeed(1): Outputs feed of userId 1 = [7, 2].

// Input: [follow(2, 1), follow(1, 2), postTweet(1, 6), getNewsFeed(1), getNewsFeed(2), unfollow(2, 1), getNewsFeed(2)]
// Output:  [null, null, null, [6], [6], null, []]
// Explanation:follow(2, 1): User with userId 2 follows user with userId 1.
// follow(1, 2): User with userId 1 follows user with userId 2.
// postTweet(1, 6): User with userId 1 posts tweet with tweetId 6.
// getNewsFeed(1): Outputs feed of userId 1 = [6].
// getNewsFeed(2): Outputs feed of userId 2 = [6]. This includes tweets of userId 1 as well.
// unfollow(2, 1): User with userId 2 unfollows user with userId 1.
// getNewsFeed(2): Outputs feed of userId 2 = [], its empty as userId 2 no longer follows userId 1 

// Approach
// The main challenge in this problem is retrieving the 10 most recent tweets across all followed users in an efficient way. Since each user may have multiple tweets, and tweets are ordered by recency, this becomes similar to merging K sorted lists (one per user). To do this optimally, we use a Max-Heap (priority queue) to always fetch the most recent tweet. The heap keeps at most one tweet from each list (user), and we simulate a merge sort–like process where we pop the latest tweet and push the next most recent tweet from the same user (if any). This ensures that we only process what's necessary instead of sorting everything or traversing all tweets.
// Maintain a map from each user to a list of their tweets (each tweet stores its timestamp).
// Maintain a map of user to set of users they follow.
// In postTweet(), add the tweet with a timestamp to the user’s list.
// In follow() and unfollow(), update the user's follow set accordingly.
// In getNewsFeed(), use a max heap to store the most recent tweets across all followed users and self.
// For each user being followed (including self), if they have tweets, push their most recent tweet into the heap along with an index pointer.
// Pop from the heap at most 10 times, each time adding that tweet ID to the result.
// If more tweets exist for that user, push the next recent tweet from their list into the heap.
// This simulates merging sorted tweet streams efficiently.
#include <bits/stdc++.h>
using namespace std;

class Twitter {
    private:
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> following;
    int time;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for (auto& tweet : tweets[userId]) {
            pq.push(tweet);
            if (pq.size() > 10)
                pq.pop();
        }

        for (int followee : following[userId]) {
            for (auto& tweet : tweets[followee]) {
                pq.push(tweet);
                if (pq.size() > 10)
                    pq.pop();
            }
        }

        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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

// Time Complexity: postTweet, follow, and unfollow run in O(1). getNewsFeed takes O(log k) where k is the number of users followed (including self), since we maintain a min-heap with at most one tweet per user and extract up to 10 tweets.
// Space Complexity: Storing tweets takes O(n), where n is total tweets. Follow relationships take O(u²) in worst case (if everyone follows everyone). Min-heap in getNewsFeed uses O(k) space, where k is number of users followed.