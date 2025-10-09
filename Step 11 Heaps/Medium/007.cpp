// Hands of Straights

// Problem Statement: You are given an array of integers hand, where hand[i] is the value on the i-th card that Alice owns. Alice wants to split her entire hand into groups such that: every group contains exactly groupSize cards, and the card values in each group form a sequence of groupSize consecutive integers (e.g. [3, 4, 5], [10, 11, 12, 13]).

// Examples
// Input : hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
// Output :  True
// Explanation :  One possible partition is [1,2,3] [2,3,4] [6,7,8].

// Input : hand = [1,2,3,4,5], groupSize = 4
// Output :  false
// Explanation :  There is no way to split the hand into groups of 4 consecutive cards.

// Algorithm
// To determine whether a hand of cards can be rearranged into groups of size `groupSize`, we can sort the cards and always try to build a group starting from the smallest available card. We greedily check if the next `groupSize - 1` consecutive cards exist and reduce their count. A `TreeMap` (in C++ or Java) or a sorted map can help maintain keys in sorted order while efficiently accessing and updating the card counts.
// Check if total number of cards is divisible by groupSize; if not, return false.
// Store the frequency of each card in a sorted data structure.
// Iterate over the sorted keys (card values) from smallest to largest.
// For each key, try to form a group of groupSize starting from that key.
// If there are not enough cards to build a group, return false.
// Decrement the counts for each card used in the group.
// If all groups are successfully formed, return true.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;

        map<int, int> mpp;
        for(int card: hand){
            mpp[card]++;
        }

        auto it = mpp.begin();

        while(it != mpp.end()){
            if(it -> second == 0){
                it++;
                continue;
            }

            int start = it -> first;
            int count = it -> second;

            for (int i = 0; i < groupSize; i++){
                if (mpp[start + i] < count) return false;
                mpp[start + i] -= count;
            }
            it++;
        }
        return true;
    }
};

// Time Complexity:O(N log N) , where N is the number of cards. We insert each card into a map which takes log N time per insertion. Then, for each unique card, we attempt to form a group of size groupSize, and this check involves accessing up to groupSize elements in the map, each in log N time.
// Space Complexity: O(N), because we store the frequency of each unique card in a map. In the worst case, all cards are unique, so the map can hold up to N entries.