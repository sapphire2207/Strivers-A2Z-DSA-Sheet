// Minimum Cost to Connect Sticks

// Problem Description
// You are given an array sticks where each element represents the length of a stick (positive integer).
// You can connect any two sticks together to form a single stick. When you connect two sticks with lengths x and y, the resulting stick has length x + y, and you must pay a cost equal to x + y.
// Your goal is to connect all the sticks together until only one stick remains. You need to find the minimum total cost to achieve this.
// For example, if you have sticks with lengths [2, 4, 3]:
// You could first connect sticks of length 2 and 3, paying cost 5, resulting in sticks [5, 4]
// Then connect the remaining two sticks of length 5 and 4, paying cost 9
// Total cost would be 5 + 9 = 14

// The strategy uses a greedy approach with a min heap. By always connecting the two shortest sticks first, we minimize the cost at each step. The algorithm repeatedly:
// Extracts the two smallest sticks from the heap
// Connects them (calculating the cost)
// Adds the cost to the running total
// Inserts the new combined stick back into the heap
// Continues until only one stick remains

// Intuition
// The key insight is that when we connect two sticks, the resulting stick will potentially be used in future connections. Since we pay the sum of lengths each time we connect, longer sticks that participate in multiple connections will contribute their length to the total cost multiple times.
// Think of it this way: if we have a very long stick, we want to use it as few times as possible in our connections. Conversely, shorter sticks should be combined early because their smaller values will be added to the total cost multiple times as they form parts of larger sticks.
// Consider why connecting the two shortest sticks is optimal at each step:
// When we connect sticks of length a and b, we pay a + b
// The resulting stick of length a + b might be used again in future connections
// If we had instead connected a short stick with a long stick early, that long stick's value would be included in more subsequent operations, increasing the total cost
// This naturally leads to a greedy strategy: always connect the two shortest available sticks. By doing this, we ensure that:
// Smaller values are "promoted" to larger sticks early
// Larger values participate in fewer connection operations
// The overall cost is minimized

// Algorithm:
// The solution implements the greedy strategy using Python's built-in heapq module, which provides a min heap implementation.
// Step 1: Initialize the Min Heap
// heapify(sticks)
// We transform the input array sticks into a min heap in-place. This operation takes O(n) time and ensures the smallest element is always at index 0.
// Step 2: Initialize Cost Counter
// ans = 0
// We maintain a variable ans to track the cumulative cost of all connections.
// Step 3: Connect Sticks Until One Remains
// while len(sticks) > 1:
// We continue the process as long as there are at least 2 sticks to connect.
// Step 4: Extract and Connect Two Smallest Sticks
// z = heappop(sticks) + heappop(sticks)
// In each iteration:
// heappop(sticks) removes and returns the smallest stick (first call)
// heappop(sticks) removes and returns the second smallest stick (second call)
// We add their lengths to get the new stick length z
// Step 5: Accumulate Cost
// ans += z
// The cost of this connection (which equals the length of the new stick) is added to our total cost.
// Step 6: Insert New Stick Back
// heappush(sticks, z)
// The newly formed stick is inserted back into the heap, maintaining the heap property.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        // Use a min-heap to always access the smallest sticks efficiently
        // This ensures we minimize the cost by combining smallest sticks first
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Add all sticks to the min-heap
        for (const int& stickLength : sticks) {
            minHeap.push(stickLength);
        }

        // Track the total cost of connecting all sticks
        int totalCost = 0;

        // Keep combining sticks until only one remains
        while (minHeap.size() > 1) {
            // Extract the two smallest sticks
            int firstSmallest = minHeap.top();
            minHeap.pop();

            int secondSmallest = minHeap.top();
            minHeap.pop();

            // Calculate the cost of combining these two sticks
            int combinedLength = firstSmallest + secondSmallest;

            // Add the cost to the total
            totalCost += combinedLength;

            // Push the combined stick back to the heap for further combinations
            minHeap.push(combinedLength);
        }

        return totalCost;
    }
};

// The time complexity is O(n × log n), where n is the length of the array sticks.
// The initial heapify(sticks) operation takes O(n) time to build a min-heap from the array.
// The while loop runs n - 1 times (until only one stick remains).
// In each iteration, we perform:
// Two heappop() operations: O(log n) each
// One heappush() operation: O(log n)
// Total per iteration: O(log n)
// Since we have n - 1 iterations, the loop contributes O(n × log n) time.
// Overall time complexity: O(n) + O(n × log n) = O(n × log n)
// The space complexity is O(n), where n is the length of the array sticks.
// The heapify() operation modifies the input array in-place and uses O(1) extra space.
// The heap operations (heappop and heappush) work on the existing array without requiring additional space proportional to the input size.
// The space is dominated by the input array itself, which has size n.
// Therefore, the space complexity is O(n).