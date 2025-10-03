// Maximum Nesting Depth of the Parentheses

// Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

// Example 1:
// Input: s = "(1+(2*3)+((8)/4))+1"
// Output: 3
// Explanation:
// Digit 8 is inside of 3 nested parentheses in the string.

// Example 2:
// Input: s = "(1)+((2))+(((3)))"
// Output: 3
// Explanation:
// Digit 3 is inside of 3 nested parentheses in the string.

// Example 3:
// Input: s = "()(())((()()))"
// Output: 3

// Constraints:
// 1 <= s.length <= 100
// s consists of digits 0-9 and characters '+', '-', '*', '/', '(', and ')'.
// It is guaranteed that parentheses expression s is a VPS.

// Approach:
// We're interested in measuring how deeply nested the parentheses are at any point in the string.
// Each opening bracket indicates going deeper into a new level of nesting.
// Each closing bracket signals returning to the previous level of nesting.
// By tracking how deep we go at each step, we can monitor the peak nesting level.
// The deepest level we reach during this traversal is the answer.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') {
                depth++;
            } else if(s[i] == ')'){
                depth--;
            }
            ans = max(ans, depth);
        }
        return ans;
    }
};

// Time Complexity: O(n), where n is the length of the string.
// Space Complexity: O(1), as only constant extra space is used.