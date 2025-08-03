// Expression Add Operators

// Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.
// Note that operands in the returned expressions should not contain leading zeros.

// Example 1:
// Input: num = "123", target = 6
// Output: ["1*2*3","1+2+3"]
// Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.

// Example 2:
// Input: num = "232", target = 8
// Output: ["2*3+2","2+3*2"]
// Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.

// Intuition (Simple Explanation)
// We are given a string of digits (like "123") and a target number (like 6). We need to insert binary operators '+', '-', or '*' between the digits to form valid expressions that evaluate to the target.
// For example:
// "1+2+3" = 6 
// "1*2*3" = 6 

// We want to try all possible ways of inserting operators, and only keep the expressions that evaluate to the target.
// We do this using recursion with backtracking, building expressions step-by-step:
// Choose a number from the string (like '1', '12', etc.)
// Add an operator (+, -, *) before it (except for the first number)
// Recurse to process the remaining digits
// At the end, if the result equals the target, we save the expression.

// Core Steps / Algorithm
// Start with recursion from index 0.
// At each step, try to take all possible substrings starting from the current index (e.g., "1", "12", "123").
// Convert the substring to a number (currRes) to evaluate.
// If it's the first number, start the expression with it (no operator).
// Else, recursively try:
// Adding + and updating the result as res + currRes
// Adding - and updating the result as res - currRes
// Adding * and fixing the precedence using:
// res - prev + (prev * currRes)
// (this backtracks the last operation and applies multiplication properly)
// If the index reaches the end of the string and result equals the target, store the expression.
// Avoid numbers with leading zeros (e.g., "05" is invalid) using:
// if (i > index && num[index] == '0') break;

// Time Complexity (TC):
// Worst-case: O(4ⁿ), where `n` is the length of the input string.
// Reason:
// At each digit, we may insert 3 operators (`+`, `-`, `*`) between digits.
// We try all partitions and operator combinations.
// Since each operator can be chosen at every position, and we can have around `n-1` positions, this leads to exponential combinations.
// Each combination takes O(n) time to build the string.
// Final TC: O(4ⁿ × n)

// Space Complexity (SC):
// The recursion depth can go up to `n`, where `n` is the length of the string.
// At each step, we build new strings for expressions (which can go up to length `2n - 1` because of numbers + operators).
// `ans` holds all valid expressions (worst-case exponential number of results).
// Final SC: O(n) recursion stack + O(4ⁿ × n) for results and expressions.

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(0, num, target, "", ans, 0, 0);
        return ans;
    }

private:
    void solve(int index, const string& num, int target, string current, vector<string>& ans, long prev, long res) {
        if (index == num.length()) {
            if (res == target) {
                ans.push_back(current);
            }
            return;
        }

        string st = "";
        long currRes = 0;
        for (int i = index; i < num.length(); i++) {
            if (i > index && num[index] == '0') break; 
            st += num[i];
            currRes = currRes * 10 + (num[i] - '0');

            if (index == 0) {
                solve(i + 1, num, target, st, ans, currRes, currRes);
            } else {
                solve(i + 1, num, target, current + "+" + st, ans, currRes, res + currRes);
                solve(i + 1, num, target, current + "-" + st, ans, -currRes, res - currRes);
                solve(i + 1, num, target, current + "*" + st, ans, prev * currRes, res - prev + (prev * currRes));
            }
        }
    }
};
