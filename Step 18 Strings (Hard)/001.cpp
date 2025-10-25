// Minimum number of bracket reversals needed to make an expression balanced

// Problem Statement: Given a string s consisting of only opening and closing brackets '(' and ')', find out the minimum number of reversals required to convert the string into a balanced expression.
// If it is not possible to make the brackets balanced, return -1. A reversal means changing '(' to ')' or vice-versa.
// Examples
// Input : s = ")(())((("
// Output : 3
// Explanation :  One way to balance is: "((())())". There is no balanced sequence that can be formed in lesser reversals.

// Input : s = "(()((()(())(("
// Output : -1
// Explanation : There's no way we can balance this sequence of braces.

// Approach
// To be balanced, every opening bracket must be matched with a closing bracket. If the string has an odd length, it’s impossible to balance, because pairs need even count. Whenever we see a closing bracket without a matching opening, we know a reversal is needed.Similarly, leftover opening brackets at the end also need to be flipped to make it balanced.
// If the string length is odd, it’s impossible to balance, return -1.
// Traverse the string and increase opening counter for '('. For ')', either cancel a previous '(' or increase the closing counter.
// Minimum reversals required = (unmatchedOpening + 1) / 2 + (unmatchedClosing + 1) / 2.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate the minimum number of reversals to balance the expression
    int minReversalsToBalance(string expression) {
        // Count of unmatched '(' brackets
        int openBrackets = 0;
        
        // Count of unmatched ')' brackets
        int closeBrackets = 0;

        // Traverse the string
        for (char ch : expression) {
            if (ch == '(') {
                // Consider '(' as unmatched for now
                openBrackets++;
            } else {
                if (openBrackets > 0) {
                    // Match this ')' with a previous '('
                    openBrackets--;
                } else {
                    // No matching '(' exists, so this ')' is unmatched
                    closeBrackets++;
                }
            }
        }

        // If total number of unmatched brackets is odd, return -1
        if ((openBrackets + closeBrackets) % 2 != 0) return -1;

        // Return minimum reversals required
        return (openBrackets + 1) / 2 + (closeBrackets + 1) / 2;
    }
};

int main() {
    // Input expression
    string expression = "(()))(";

    // Create object of Solution
    Solution solver;

    // Get result from function
    int result = solver.minReversalsToBalance(expression);

    // Print the result
    cout << "Minimum reversals required: " << result << endl;

    return 0;
}

// Complexity Analysis
// Time Complexity: O(N), we traverse the string once processing each bracket in constant time.
// Space Complexity: O(1), constant extra space is used.