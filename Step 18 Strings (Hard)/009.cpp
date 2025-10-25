// Count palindromic subsequence in given string

// Problem Statement: Given a string s, count the total number of distinct palindromic subsequences present in it. A palindromic subsequence is a sequence derived by deleting zero or more characters without changing the order such that the resultant string reads the same forwards and backwards.
// Examples
// Input: s = "bccb"
// Output: 6
// Explanation: The 6 distinct palindromic subsequences are "b", "c", "bb", "cc", "bcb", "bccb".

// Input: s = "abcd"
// Output: 4
// Explanation: The 4 distinct palindromic subsequences are "a", "b", "c" and "d".

// Brute Force Approach
// We generate all possible subsequences of the string and check each one to see if it is a palindrome. To avoid duplicates, we use a set to store only unique palindromic subsequences.
// Generate all possible subsequences of the string using recursion or bitmasking.
// For each subsequence, check if it is a palindrome.
// If yes, insert it into a set to maintain uniqueness.
// Return the size of the set at the end.
#include <bits/stdc++.h>
using namespace std;

// Solution class to count palindromic subsequences using brute force
class Solution {
public:
    // Function to check if a given string is a palindrome
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }

    // Recursive function to generate subsequences and count palindromes
    int count(string s, string curr, int index) {
        if (index == s.length()) {
            if (!curr.empty() && isPalindrome(curr)) return 1;
            return 0;
        }

        // Include current character
        int include = count(s, curr + s[index], index + 1);

        // Exclude current character
        int exclude = count(s, curr, index + 1);

        return include + exclude;
    }

    // Public function to start recursion
    int countPalindromicSubsequences(string s) {
        return count(s, "", 0);
    }
};

// Main function
int main() {
    Solution sol;
    string s = "abcb";
    cout << sol.countPalindromicSubsequences(s) << endl;
    return 0;
}

// Complexity Analysis
// Time Complexity: O(2ⁿ · n), all subsequences are generated and each is checked for being a palindrome.
// Space Complexity: O(n), due to recursion stack or temporary string storage.

// Optimal Approach - Memoization
// Instead of generating all subsequences, we recursively explore valid palindromic ranges and store intermediate results to avoid repeated computation. This reduces the time complexity from exponential to polynomial time.
// Start with the full string and try to count palindromic subsequences between two positions.
// If the part is empty, return 0 since there is no subsequence.
// If there is only one letter, return 1 since a single letter is always a palindrome.
// If the first and last letters of the part are same, count palindromes in the middle, count without the first, count without the last, and combine all, adding one extra for the new pair.
// If the first and last letters are different, count from excluding the first, count from excluding the last, and remove the overlap that was counted in both.
// Save each result in a table so that if the same part is needed again, we directly return the saved answer.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to count palindromic subsequences using memoization
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        // Initialize a 2D DP array with -1
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // Call the recursive function on the full string
        return count(s, 0, n - 1, dp);
    }

private:
    // Recursive function with memoization to count palindromic subsequences
    int count(string &s, int i, int j, vector<vector<int>> &dp) {
        // If i > j, no valid subsequence
        if (i > j) return 0;

        // If i == j, single character is a palindrome
        if (i == j) return 1;

        // If already computed, return from dp
        if (dp[i][j] != -1) return dp[i][j];

        // If characters match, count all palindromic subsequences 
        // from both ends and middle + 1
        if (s[i] == s[j])
            dp[i][j] = count(s, i + 1, j, dp) + 
                             count(s, i, j - 1, dp) + 1;
        else
            // Subtract overlapping part if chars don’t match
            dp[i][j] = count(s, i + 1, j, dp) + count(s, i, j - 1, dp) -
                              count(s, i + 1, j - 1, dp);

        return dp[i][j];
    }
};

// Main function to run the solution
int main() {
    Solution sol;
    string s = "aab";
    cout << sol.countPalindromicSubsequences(s) << endl;
    return 0;
}

// Complexity Analysis
// Time Complexity: O(n²), each substring state is computed once and reused.
// Space Complexity: O(n² + n), space for the memoization table and recursion stack.

// Optimal Approach - Tabulation
// Instead of checking all subsequences or recursively exploring combinations, this approach builds a solution by solving smaller problems first and combining them to solve larger ones. The idea is to use a table to store the number of palindromic subsequences for every possible substring. We take advantage of overlapping subproblems and avoid redundant recalculations. The DP table ensures that every possible substring is considered only once in increasing order of length. This leads to a more efficient and scalable solution.
// Make a table to store the number of palindromic subsequences for every part of the string.
// Set the answer to 1 for all single letters since each one is a palindrome.
// Start from shorter parts of the string and move to longer ones step by step.
// For each part, check the first and last letters.
// If they are same, use the answers from inner parts and also add extra for the pair.
// If they are different, add answers from the two smaller parts and subtract the overlapping part to avoid repeating.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to count palindromic subsequences using tabulation
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        // Create a 2D DP table
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Every single character is a palindrome
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // Fill the DP table for substrings of increasing length
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                // If characters match
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
                else
                    // Remove overlapping part
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            }
        }

        return dp[0][n - 1];
    }
};

// Main function to run the solution
int main() {
    Solution sol;
    string s = "aab";
    cout << sol.countPalindromicSubsequences(s) << endl;
    return 0;
}

// Complexity Analysis
// Time Complexity: O(n²), all substrings of all lengths are processed once.
// Space Complexity: O(n²), 2D DP table is used to store the results of subproblems.