// Remove Outermost Parentheses

// A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.
// For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
// A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.
// Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.
// Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

// Example 1:
// Input: s = "(()())(())"
// Output: "()()()"
// Explanation: 
// The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
// After removing outer parentheses of each part, this is "()()" + "()" = "()()()".

// Example 2:
// Input: s = "(()())(())(()(()))"
// Output: "()()()()(())"
// Explanation: 
// The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
// After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".

// Example 3:
// Input: s = "()()"
// Output: ""
// Explanation: 
// The input string is "()()", with primitive decomposition "()" + "()".
// After removing outer parentheses of each part, this is "" + "" = "".

// Use a nesting level counter (level) to track how deep you are inside parentheses:
// level = 0 → we are outside any primitive (or at the start of a new primitive).
// level = 1 → we just entered the first level of a primitive (outermost '(').
// level > 1 → we are inside the primitive, not at the outer layer.

// Rule for adding characters:
// Open parenthesis '(':
// Add to result only if level > 0. Why? Because the first '(' of a primitive (level = 0) is the outermost and should be skipped.
// Close parenthesis ')':
// Decrement level first, then add to result only if level > 0. Why? Because when you reach level = 0, that ')' is the closing of the outermost layer and should be skipped.

// Why It Works
// The counter (level) ensures that only inner parentheses of each primitive are added to result.
// The outermost '(' and ')' of each primitive are automatically ignored because:
// '(' is skipped when level = 0
// ')' is skipped when level = 1 (because decrementing makes level = 0)
// This works regardless of nesting depth, because the counter accurately tracks the current level of nesting.
// In short
// By keeping a nesting counter and only adding parentheses when inside a primitive (not at the outermost layer), we automatically remove the outermost parentheses of each primitive substring.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string answer = "";
        int level = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                if(level > 0) answer += '(';
                level++;
            }
            else{
                level--;
                if(level > 0) answer += ')';
            }
        }

        return answer;
    }
};

// Time Complexity: O(n), since we are performing a single traversal of the string.
// Space Complexity: O(1), since we are using a few variables to track the current state.