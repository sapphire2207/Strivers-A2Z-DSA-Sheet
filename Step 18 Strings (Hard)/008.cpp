// Longest Happy Prefix

// Problem Statement: Given a string s, return the longest happy prefix of s. A happy prefix is a string that is both a proper prefix and a proper suffix.
// If no such prefix exists, return an empty string .
// Note: A proper prefix/proper suffix of a string is any prefix/suffix that is not equal to the entire string.

// Examples
// Input: s = "ababab"
// Output: "abab"
// Explanation:  "abab" is the longest prefix which is also suffix. They can overlap in the original string.

// Input: s = "aaaa"
// Output: "aaa"
// Explanation: "aaa" is the longest proper prefix which is also a proper suffix in the string "aaaa".

// Brute-Force Approach
// The goal is to find the longest substring that exists at both the start and end of the string, but it must not be the entire string itself. In the brute force approach, we try all possible lengths of such substrings, beginning with the longest possible and gradually reducing the size. At each step, we compare a prefix from the beginning with a suffix from the end. As soon as we find a match, we return it, since we are checking from longest to shortest. This method is simple but not optimal for very large strings.
// Check for every possible substring starting from the beginning of the string.
// For each such substring, check if the same substring also appears at the end of the string.
// Start checking from the longest possible substring and move to shorter ones.
// Return the first substring that appears at both the start and end.
// If no such substring exists, return an empty result.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the longest happy prefix
    string longestPrefix(string s) {
        int n = s.size();

        // Loop through all possible prefix-suffix lengths
        for (int len = n - 1; len > 0; len--) {
            // Compare prefix and suffix of current length
            if (s.substr(0, len) == s.substr(n - len, len)) {
                return s.substr(0, len);
            }
        }

        // Return empty string if no happy prefix found
        return "";
    }
};

int main() {
    Solution sol;
    string s = "levellevel";
    cout << sol.longestPrefix(s) << endl;
    return 0;
}

// Complexity Analysis
// Time Complexity: O(n²), for each of the n possible lengths we compare up to n characters.
// Space Complexity: O(n), for storing substrings during comparison.

// Optimal Approach
// In the brute-force approach, we repeatedly compare the prefix and suffix of the string for every possible length, which leads to repeated and redundant comparisons. This results in a time complexity of O(n²), which is inefficient for longer strings.

// The KMP algorithm optimizes this process by avoiding unnecessary re-checks. It builds a table (known as the LPS array) that stores the length of the longest prefix which is also a suffix at every index. Instead of restarting the match from the beginning every time a mismatch occurs, we use the LPS array to jump to the next possible position, reducing the total number of comparisons.
// Make an array to store the length of the longest prefix which is also a suffix at each position.
// Start checking the string from the second character.
// If the current character matches the current prefix character, increase the match length and store it in the array.
// If there is a mismatch, look back in the array to find the previous best prefix length and try again from there.
// Repeat this until you reach the end of the string.
// The last value in the array tells you the length of the longest prefix which is also a suffix.
// Take the substring from the beginning of the string up to that length and return it.
#include <bits/stdc++.h>
using namespace std;

// Solution class containing the method to find the longest happy prefix
class Solution {
public:
    // Function to find the longest happy prefix
    string longestPrefix(string s) {
        // Create a vector to store the prefix-suffix lengths
        vector<int> lps(s.length(), 0);

        // Pointer to track length of previous longest prefix suffix
        int len = 0;

        // Start from second character
        for (int i = 1; i < s.length(); i++) {
            // If characters match, increment length and store in lps
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
            }
            // If mismatch occurs and len is not zero, fallback using lps
            else if (len != 0) {
                len = lps[len - 1];
                i--; // retry with same i
            }
            // If no match and len is 0, keep lps as 0
        }

        // Return the prefix with length equal to the last lps value
        return s.substr(0, lps[s.length() - 1]);
    }
};

// Main function to test the solution
int main() {
    Solution sol;
    string s = "levellevel";
    cout << sol.longestPrefix(s) << endl;
    return 0;
}

// Complexity Analysis
// Time Complexity: O(n), we traverse the string once to compute the LPS array and use it to get the result.
// Space Complexity: O(n), extra space is used for the LPS array of length n.
