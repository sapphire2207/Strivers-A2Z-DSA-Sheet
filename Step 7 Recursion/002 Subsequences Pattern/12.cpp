// Letter Combinations of a Phone Number

// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
// Example 1:
// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

// Example 2:
// Input: digits = ""
// Output: []

// Example 3:
// Input: digits = "2"
// Output: ["a","b","c"] 

// Approach:
// Map Digits to Letters:
// Use an unordered_map<char, string> to store mappings like '2' → "abc", '3' → "def", etc.
// Recursive Function (helper):
// It builds combinations character by character.
// Parameters track the current index, partial string, and result list.
// Base Case:
// If we've reached the end of the digits string, push the current built string (temp) into the answer list.
// Recursive Case:
// For the current digit, loop through all possible letters.
// Add each letter to temp, call helper for the next digit, then remove the letter (backtrack).
// Start the Process:
// In letterCombinations, call helper with index 0 and an empty string if digits aren't empty.

// For "23":
// Start with ""
// Add a, then try d, e, f → ad, ae, af
// Backtrack to b, try again → bd, be, bf
// Then c → cd, ce, cf

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int i, string &digits, string &temp, vector<string> &ans, unordered_map<char, string> &mpp) {
        if (i == digits.size()) {
            if (!temp.empty()) ans.push_back(temp);
            return;
        }

        string str = mpp[digits[i]];
        for (int j = 0; j < str.size(); j++) {
            temp.push_back(str[j]);
            helper(i + 1, digits, temp, ans, mpp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";

        vector<string> ans;
        string temp;
        if (!digits.empty()) {
            helper(0, digits, temp, ans, mpp);
        }
        return ans;
    }
};

// Time Complexity (TC):
// The time complexity is O(3ⁿ × 4ᵐ), where `n` is the number of digits that map to 3 letters (`2`, `3`, `4`, `5`, `6`, `8`) and `m` is the number of digits that map to 4 letters (`7`, `9`). This is because for each digit, we generate all combinations by trying every possible letter it maps to. In the worst case (e.g., all digits are `7` or `9`), each digit contributes 4 branches to the recursion tree, leading to exponential growth in total combinations.

// Space Complexity (SC):
// The space complexity is O(N × K), where `N` is the total number of combinations generated (i.e., the output size) and `K` is the average length of each combination (equal to the number of digits). Additionally, there is **O(K)** auxiliary space used by the recursion stack for backtracking (depth of recursion equals number of digits). The unordered map uses constant space since it stores only fixed digit-to-letters mappings.
