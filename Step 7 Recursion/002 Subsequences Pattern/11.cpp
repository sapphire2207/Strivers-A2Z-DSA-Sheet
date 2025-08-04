// Combination Sum III

// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

// Example 1:
// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Explanation:
// 1 + 2 + 4 = 7
// There are no other valid combinations.

// Example 2:
// Input: k = 3, n = 9
// Output: [[1,2,6],[1,3,5],[2,3,4]]
// Explanation:
// 1 + 2 + 6 = 9
// 1 + 3 + 5 = 9
// 2 + 3 + 4 = 9
// There are no other valid combinations.

// Intuition
// To find the solution, we can utilize a Depth First Search (DFS) algorithm. DFS will help us explore all possible combinations of numbers recursively while adhering to the constraints. Here's the intuition behind using DFS for this problem:

// We begin by considering numbers from 1 to 9 and use each of them as a starting point of a combination.
// To build a combination, we add a number to the current combination (t in the given code) and recursively call the DFS function to add the next number.
// While adding the new number, we have three conditions to check:
// We must not exceed the target sum n.
// We should not use more than k numbers.
// We cannot use numbers greater than 9.
// If the sum of numbers in the current combination equals n and we have used exactly k numbers, then we found a valid combination which we add to the answer list (ans).
// After exploring a number's inclusion, we backtrack by removing the number from the current combination and exploring the possibility of not including that number.
// Through this process of including and excluding each number, and backtracking after exploring each possibility, we ensure that all valid combinations are found.
// Each combination is built up incrementally from the smaller numbers towards the larger ones to avoid repeated combinations and maintain uniqueness.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void helper(int i, int k, int sumTillNow, int n, vector<vector<int>> &result, vector<int> &ans){
        if(sumTillNow > n) return;
        if(k == 0){
            if(sumTillNow == n){
                result.push_back(ans);
            }
            return;
        }
        if(i == 10) return;

        ans.push_back(i);
        helper(i + 1, k - 1, sumTillNow + i, n, result, ans);
        ans.pop_back();
        helper(i + 1, k, sumTillNow, n, result, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> ans;
        helper(1, k, 0, n, result, ans);
        return result;
    }
};

// Time Complexity (TC):
// The time complexity is O(C(9, k)), which represents all possible combinations of choosing k numbers from 1 to 9. This is because for each number, the algorithm decides whether to include it or not, and it explores only valid paths where the total number of elements is k and their sum is n. Since k is at most 9, the total combinations are limited and manageable.

// Space Complexity (SC):
// The space complexity is O(k) due to the depth of the recursive call stack, as the algorithm explores combinations by adding up to k numbers. If we include the output (all valid combinations), then the total space would be O(C(9, k) * k), as we might store that many combinations each of size k.