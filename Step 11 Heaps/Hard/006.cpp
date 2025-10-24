// Top K Frequent Elements

// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

// Example 1:
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

// Example 2:
// Input: nums = [1], k = 1
// Output: [1]

// Example 3:
// Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
// Output: [1,2]

// Constraints:
// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// k is in the range [1, the number of unique elements in the array].
// It is guaranteed that the answer is unique.

// Approach:
// The idea is to use a hashmap to store each element along with its frequency, allowing insertion and updates in constant time. After building the frequency map, sort the elements in decreasing order of their frequency. To find the top k elements, simply take the first k elements from the sorted list.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }

        using FreqNumPair = pair<int, int>;
        priority_queue<FreqNumPair, vector<FreqNumPair>, greater<FreqNumPair>> minHeap;

        for(auto it: mpp){
            minHeap.push({it.second, it.first});

            if(minHeap.size() > k){
                minHeap.pop();
            }
        }

        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};