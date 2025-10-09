// Task Scheduler

// You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.
// Return the minimum number of CPU intervals required to complete all tasks.

// Example 1:
// Input: tasks = ["A","A","A","B","B","B"], n = 2
// Output: 8
// Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
// After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.

// Example 2:
// Input: tasks = ["A","C","A","B","D","B"], n = 1
// Output: 6
// Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.
// With a cooling interval of 1, you can repeat a task after just one other task.

// Example 3:
// Input: tasks = ["A","A","A", "B","B","B"], n = 3
// Output: 10
// Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.
// There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.

// Constraints:
// 1 <= tasks.length <= 104
// tasks[i] is an uppercase English letter.
// 0 <= n <= 100

// Approach:
// We always want to execute the most frequent remaining task first  to minimize idle times.
// - A **max heap (priority_queue)** stores the counts of remaining tasks  (so we can always pick the most frequent one).
// - After executing a task, it enters a **cooldown period** of length 'n'. We use a **queue** to track when each task becomes available again.
// 1. Count frequencies of each task using an unordered_map.
// 2. Push all task frequencies into a max heap.
// 3. Keep a queue of pairs {remaining_count, available_time}, 
//    representing tasks cooling down.
// 4. For each time unit:
//    a) If heap not empty → execute top task (most frequent one).
//       - Decrement its remaining count.
//       - If still remaining, push into queue with cooldown time = current_time + n.
//    b) If the front of the queue’s cooldown time == current_time, 
//       push it back into the heap.
// 5. Continue until both heap and queue are empty.
// 6. The final 'time' is the answer.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char task : tasks) {
            freq[task]++;
        }

        priority_queue<int> maxHeap;
        for (auto& entry : freq) {
            maxHeap.push(entry.second);
        }

        queue<pair<int, int>> q;
        int time = 0;

        while (!maxHeap.empty() || !q.empty()) {
            time++;

            if (!maxHeap.empty()) {
                int count = maxHeap.top();
                maxHeap.pop();
                count--;
                if (count > 0) {
                    q.push({count, time + n});
                }
            }

            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        
        return time;
    }
};

// TIME COMPLEXITY: O(T * log K)
// where:
// - T = total number of tasks
// - K = number of unique tasks
// Reason: Each task is pushed and popped from the heap at most once, and heap operations cost O(log K).

// SPACE COMPLEXITY: O(K)
// We use extra space for:
// - frequency map (O(K))
// - max heap (O(K))
// - queue (O(K))