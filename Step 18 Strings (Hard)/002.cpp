// Count and Say

// Problem Statement: The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
// countAndSay(1) = "1"
// countAndSay(n) is the run-length encoding of countAndSay(n - 1).
// Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".
// Given a positive integer n, return the nth element of the count-and-say sequence.

// Examples
// Input: 4
// Output: "1211"
// Explanation:  
// countAndSay(1) = "1"
// countAndSay(2) = RLE of "1" = "11"
// countAndSay(3) = RLE of "11" = "21"
// countAndSay(4) = RLE of "21" = "1211"

// Input: 1
// Output: "1"
// Explanation: This is the base case.

// Algorithm
// We are generating each term in a sequence by describing the previous term. For example, if the previous term is 1211, we say it as "one 1, one 2, two 1s", giving 111221.
// Start from the first term as "1".
// For each new term, scan the previous term from left to right and count how many times the current digit appears consecutively.
// Append the count followed by the digit to build the next term.
// Repeat this process until reaching the required term.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";

        for(int i = 1; i < n; i++){
            string current = "";
            int count = 1;
            for(int j = 1; j < result.size(); j++){
                if(result[j] == result[j-1]){
                    count++;
                }
                else {
                    current += to_string(count) + result[j-1];
                    count = 1;
                }
            }
            current += to_string(count) + result.back();
            result = current;
        }
        return result;
    }
};

// Complexity Analysis
// Time Complexity: O(n * 2^n), there can be n iterations, with string length of upto 2^n characters.
// Space Complexity: O(2^n), Final string length can reach upto 2^n