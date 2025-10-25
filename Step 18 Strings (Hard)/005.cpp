// Z Function

// Problem Statement: Given two strings, one is a text string and the other is a pattern string. Print the indexes of all occurrences of the pattern string in the text string using the Z function algorithm. Use 0-based indexing while returning the indices.
// Examples
// Input: text = "xyzabxyzabxyz", pattern = "xyz"
// Output: [0, 5, 10]
// Explanation:  The pattern "xyz" occurs three times in text, starting at indices 0, 5, and 10.

// Input: text = "cabcdab", pattern = "abc"
// Output: [1]
// Explanation: The pattern "abc" occurs one time in text, starting at index 1.

// Z Function
// Why do we use Z-Function Algorithm?
// When we want to find all occurrences of a pattern in a large text, the Z-function provides a fast and elegant way to do it in linear time. Unlike Rabin-Karp which uses hashing, the Z-algorithm relies on prefix matching using a sliding window.
// The idea is to construct a new string by concatenating the pattern, a special separator (like $), and the text. We then compute the Z-array, which tells us for each position in this string, how many characters match the prefix of the entire string. A full match (Z-value equal to pattern length) tells us that the pattern occurs in the text at that position.
// This method is fast because it reuses previous comparisons using a window-based approach, and avoids unnecessary checks.
// Construct a new string by joining the pattern, a special character (e.g., $), and the text.
// Compute the Z-array for this combined string.
// The Z-array stores, at each index, the length of the longest prefix match starting from that index.
// For every position in the Z-array where the value is equal to the length of the pattern, it means the pattern occurs in the text at that position.
// Collect and return all such indices as positions where the pattern occurs in the text.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to compute Z-array for the given string
    vector<int> computeZArray(const string& s) {
        int n = s.length();
        vector<int> z(n, 0);
        int left = 0, right = 0;

        // Traverse the string to fill Z-array
        for (int i = 1; i < n; i++) {
            if (i <= right)
                z[i] = min(right - i + 1, z[i - left]);

            // Expand the Z-box by matching characters
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;

            // Update the window if we expanded beyond right
            if (i + z[i] - 1 > right) {
                left = i;
                right = i + z[i] - 1;
            }
        }

        return z;
    }

    // Function to find all occurrences of pattern in text using Z-function
    vector<int> zFunctionSearch(const string& text, const string& pattern) {
        // Combine pattern, separator, and text
        string combined = pattern + "$" + text;

        // Compute Z-array for combined string
        vector<int> z = computeZArray(combined);
        vector<int> result;

        // Check where Z value equals pattern length
        for (int i = pattern.length() + 1; i < combined.length(); i++) {
            if (z[i] == pattern.length()) {
                // Match found, calculate original text index
                result.push_back(i - pattern.length() - 1);
            }
        }

        return result;
    }
};

int main() {
    string text = "ababcababc";
    string pattern = "ab";

    Solution sol;
    vector<int> indices = sol.zFunctionSearch(text, pattern);

    cout << "Pattern found at indices: ";
    for (int index : indices) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}

// Complexity Analysis
// Time Complexity: O(n + m), where n is the length of the text string and m is the length of the pattern string. The Z-array is computed in linear time using a window technique that avoids unnecessary comparisons.
// Space Complexity: O(n + m), to store the combined string and the Z-array used for processing.