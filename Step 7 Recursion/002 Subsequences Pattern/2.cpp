// Generate Parentheses

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// Example 1:
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

// Solution Approach:
// The solution uses the DFS (Depth First Search) algorithm to generate the combinations. It employs recursion as a mechanism to explore all possible combinations and backtracks when it hits a dead end (an invalid combination).
// Here's a step-by-step breakdown of the DFS algorithm as implemented in the provided solution:
// Initial Call: The generateParenthesis function initiates the process by calling the nested dfs (Depth First Search) function with initial values of zero used opening parentheses (l), zero used closing parentheses (r), and an empty string for the current combination (t).
// DFS Function: This is the recursive function that contains the logic for the depth-first search. It takes three parameters:
// l: The number of opening parentheses used so far.
// r: The number of closing parentheses used so far.
// t: The current combination string formed by adding parentheses.
// Base Case: The recursion has two base cases within the DFS function: 
// a. Invalid Condition: When the number of used opening parentheses l is more than n, or the closing parentheses r is more than n or more than l, it indicates an incorrect combination. The function returns without doing anything. 
// b. Valid Combination: When both l and r equal n, it indicates that a valid combination of parentheses has been found. The current combination string t is added to the solution set ans.
// Recursive Exploration: If neither base case is met, the function continues to explore:
// Adding an opening parenthesis: If not all n opening parentheses have been used (l < n), the dfs function calls itself with l + 1, r, and appends "(" to the current string t.
// Adding a closing parenthesis: If the number of closing parentheses used is less than the number of opening parentheses (r < l), it implies that there are some unmatched opening parentheses. Thus, the dfs function calls itself with l, r + 1, and appends ")" to t.
// By calling these two lines of code, we ensure that we explore the decisions to either add an opening parenthesis or a closing one, thus generating all valid paths.
// Storage of Valid Combinations: The ans list is the container that holds all valid combinations. Each time a complete valid combination is generated, it's added to this list. After all recursive calls are completed, ans will contain all the possible well-formed parentheses combinations.
// Return Result: Finally, once all possible combinations have been explored, the ans list is returned as the result of the generateParenthesis function.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int leftCount, int rightCount, string current, vector<string> &result, int n){
        if(leftCount > n || rightCount > n || leftCount < rightCount) return;

        if(leftCount == n && rightCount == n){
            result.push_back(current);
            return;
        }

        dfs(leftCount + 1, rightCount, current + "(", result, n);
        dfs(leftCount, rightCount + 1, current + ")", result, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        dfs(0, 0, "", result, n);
        return result;
    }
};

// Time Complexity
// The time complexity of the given code is O(4^n / sqrt(n)). This complexity arises because each valid combination can be represented by a path in a decision tree, which has 2n levels (since we make a decision at each level to add either a left or a right parenthesis, and we do this n times for each parenthesis type). However, not all paths in the tree are valid; the number of valid paths follows the nth Catalan number, which is proportional to 4^n / (n * sqrt(n)), and n is a factor that represents the polynomial part that gets smaller as n gets larger. Since we're looking at big-O notation, we simplify this to 4^n / sqrt(n) for large n.

// Space Complexity
// The space complexity is O(n) because the depth of the recursive call stack is proportional to the number of parentheses to generate, which is 2n, and the space required to store a single generated set of parentheses is also linear to n. Hence, the complexity due to the call stack is O(n). The space used to store the answers is separate and does not affect the complexity from a big-O perspective. Keep in mind that the returned list itself will contain O(4^n / sqrt(n)) elements, and if you consider the space for the output list, the overall space complexity would be O(n * 4^n / sqrt(n)), which includes the length of each string times the number of valid strings. Typically, the space complexity considers only the additional space required, not the space for the output. Therefore, we only consider the O(n) space used by the call stack for our space complexity analysis.