// Valid Parenthesis String

// Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
// The following rules define a valid string:
// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
// Example 1:
// Input: s = "()"
// Output: true
// Example 2:
// Input: s = "(*)"
// Output: true
// Example 3:
// Input: s = "(*))"
// Output: true

// Brute Force:
// We try all possible replacements for * using recursion.
// Base Cases:
// If count of ( minus ) goes negative at any point → return False.
// If we reach the end of the string, check if count is 0.
// Recursively try replacing * with (, ), or "".
// TC: O(3^n)
// Since we explore all three possibilities for every *, this solution is exponential.
// SC: O(n) (Recursion Depth)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool helper(string s, int index, int count){
        if(count < 0) return false;
        if(index == s.size()){
            return (count == 0);
        }
        if(s[index] == '('){
            return helper(s, index + 1, count + 1);
        }
        if(s[index] == ')'){
            return helper(s, index + 1, count - 1);
        }
        return helper(s, index + 1, count + 1) || helper(s, index + 1, count - 1) || helper(s, index + 1, count);
    }

    bool checkValidString(string s) {
        return helper(s, 0, 0);
    }
};


// Optimal Solution:
// We keep track of the possible range of open parenthesis count using two variables:
// min: The minimum number of open brackets required.
// max: The maximum number of open brackets possible.
// Traverse the string and update min and max:
// If ( appears: Increment both min and max by 1.
// If ) appears: Decrement both min and max by 1.
// If * appears: It can act as:
// ( (increase max)
// ) (decrease min)
// Empty (no change)
// If max becomes negative at any point, return false (too many )).
// If min is 0 at the end, the string is valid.
// TC: O(N)
// SC: O(1)
class Solution {
public:
    bool checkValidString(string s) {
        int min = 0;
        int max = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                min = min + 1;
                max = max + 1;
            }
            else if(s[i] == ')'){
                min = min - 1;
                max = max - 1;
            }
            else{
                min = min - 1;
                max = max + 1;
            }
            if(min < 0) min = 0;
            if(max < 0) return false;
        }
        return (min == 0);
    }
};