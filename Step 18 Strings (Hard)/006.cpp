// KMP Algorithm or LPS Array

// Problem Statement: Given two strings, one is a text string and the other is a pattern string. Find and print the indices of all the occurrences of the pattern string within the text string. Use 0-based indexing for the indices, and ensure that the indices are in ascending order. If the pattern does not occur in the text, return an empty list.
// Implement this solution using the Knuth-Morris-Pratt (KMP) algorithm for efficient pattern matching.
// Examples
// Input: text = "abracadabra", pattern = "abra"
// Output: [0, 7]
// Explanation:  The pattern "abra" appears at the 0st and 7th positions in the text "abracadabra".

// Input: text = "abcabcabc", pattern = "abc"
// Output: [0, 3, 6]
// Explanation: The pattern "abc" appears at the 0st, 3th, and 6th positions in the text "abcabcabc".

// KMP Algorithm
// Why do we use KMP Algorithm (LPS Array)?
// When we search for a pattern in a text using a basic approach, we often end up checking the same characters again after a mismatch. This makes the process slow, especially if the pattern has repeated parts.
// The KMP algorithm avoids this by using a helper array called the LPS (Longest Prefix which is also Suffix) array. It tells us how much of the pattern we can skip when a mismatch happens.
// This helps us search the pattern in the text quickly without going backward in the text or rechecking already matched characters.
// First, create the LPS array. It stores, for each index, the length of the longest prefix of the pattern which is also a suffix.
// Start matching the pattern with the text from left to right.
// If the characters match, move forward in both the pattern and the text.
// If there’s a mismatch after some matches, use the LPS array to move the pattern pointer to the correct position without going back in the text.
// When the whole pattern matches, store the index and continue searching using LPS.
// Repeat this process until the entire text has been checked.
// Return all the starting positions where the pattern is found in the text.

#include<bits/stdc++.h>
using namespace std;

// Class that contains the KMP algorithm and LPS array construction
class Solution {
public:
    // Function to compute the LPS (Longest Prefix Suffix) array
    vector<int> computeLPS(string pattern) {
        // Create LPS array initialized with 0
        vector<int> lps(pattern.length(), 0);

        // Length of the previous longest prefix which is also a suffix
        int len = 0;

        // Start from the second character of the pattern
        int i = 1;

        // Loop to fill the LPS array
        while (i < pattern.length()) {
            // If current character matches the character at len
            if (pattern[i] == pattern[len]) {
                // Increase length of current matching prefix
                len++;
                // Assign it to lps[i]
                lps[i] = len;
                // Move to next index
                i++;
            } else {
                // If mismatch and len is not 0, try shorter previous prefix
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    // If no prefix match found, set lps[i] to 0
                    lps[i] = 0;
                    // Move to next index
                    i++;
                }
            }
        }
        // Return the complete LPS array
        return lps;
    }

    // Function to search pattern in text using KMP
    vector<int> KMP(string text, string pattern) {
        // Preprocess the pattern and compute LPS array
        vector<int> lps = computeLPS(pattern);
        // Vector to store the starting indices of all matches
        vector<int> result;
        // Pointers for text and pattern
        int i = 0;
        int j = 0;

        // Loop through the text
        while (i < text.length()) {
            // If characters match, move both pointers
            if (text[i] == pattern[j]) {
                i++;
                j++;
            }
            // If the whole pattern is matched
            if (j == pattern.length()) {
                // Store the index of match
                result.push_back(i - j);

                // Use LPS to continue searching
                j = lps[j - 1];
            }
            // If mismatch occurs after some matches
            else if (i < text.length() && text[i] != pattern[j]) {
                // Use LPS to avoid unnecessary comparisons
                if (j != 0) {
                    j = lps[j - 1];
                } else {

                    // Move forward in text if j is at start
                    i++;
                }
            }
        }
        // Return all found indices
        return result;
    }
};

// Main function to test the KMP search
int main() {
    // Define the text string
    string text = "ababcababcabc";
    // Define the pattern to search
    string pattern = "abc";

    // Create an object of the Solution class
    Solution sol;

    // Call the KMP function to get all match indices
    vector<int> matches = sol.KMP(text, pattern);

    // Output the results
    cout << "Pattern found at indices: ";
    for (int idx : matches) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}

// Complexity Analysis
// Time Complexity: O(n + m), where n is the length of the text and m is the length of the pattern. This is because both the LPS preprocessing and the pattern searching phases take linear time.
// Space Complexity: O(m), used for storing the LPS array of the pattern.