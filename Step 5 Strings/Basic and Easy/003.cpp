// Largest Odd Number in a String

// Problem Statement: Given a string s, representing a large integer, the task is to return the largest-valued odd integer (as a string) that is a substring of the given string s.
// The number returned should not have leading zero's. But the given input string may have leading zero.
    
// Example 1
// Input: s = "5347"
// Output: "5347"
// Explanation: The odd numbers formed by the given string are → 5, 3, 53, 347, 5347. The largest odd number without leading zeroes is 5347.

// Example 2
// Input: s = "0214638"
// Output: "21463"
// Explanation: The odd numbers formed by the string are → 1, 3, 21, 63, 463, 1463, 21463. We can't use numbers starting with 0, so the largest valid odd number is 21463.

// Solution Approach:
// Focus on finding the longest valid odd number starting from the original string.
// An odd number must end with an odd digit, so we look for the last odd digit when scanning from the end.
// Leading zeroes don’t add value to the number, so we aim to remove them for a cleaner representation.
// Once the endpoint (last odd digit) is determined, we identify the starting point by skipping any leading zeroes before it.
// Extract the portion between these two positions, this gives the largest possible odd integer from the string.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int index = -1;
        for(int i = n - 1; i >= 0; i--){
            if((num[i] - '0') % 2 == 1){
                index = i;
                break;
            }
        }

        int i = 0;
        while(i <= index && num[i] == '0') i++;

        return num.substr(i, index - i + 1);
    }
};

// Time Complexity: O(N), since the loop runs once through the string of length N.
// Space Complexity: O(1), as we are using only a constant amount of extra space.