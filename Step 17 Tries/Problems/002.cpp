// Longest String with All Prefixes

// Problem Statement: Given a string array nums of length n. A string is called a complete string if every prefix of this string is also present in the array nums. Find the longest complete string in the array nums.
// If there are multiple strings with the same length, return the lexicographically smallest one and if no string exists, return None

// Examples
// Input: nums = ["n", "ni", "nin", "ninj" , "ninja" , "nil" ]
// Output: "ninja"
// Explanation: The word "ninja" is the longest word which has all its prefixes present in the array.

// Input: nums = [ "ninja" , "night" , "nil" ]
// Output: None
// Explanation: There is no string that has all its prefix present in array. So we return None.

// Algorithm
// To find the longest complete string, we need to check each string in the array and verify whether all its prefixes are present in the array. A complete string means that for a word like "apple", the strings "a", "ap", "app", "appl", and "apple" must all exist in the array. We do this check for every string and track the longest one that satisfies the condition. If two strings are of the same length, we return the lexicographically smaller one. This approach works but can be slow because we are repeatedly checking prefixes for all words.
// Loop through every string in the array.
// For each string, check if all its prefixes exist in the array.
// To check a prefix, go from the first character to the full string, slicing the prefix each time.
// If all prefixes of the current string are found, compare it with the current best answer.
// In case of a tie in length, choose the one that comes first alphabetically.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the longest complete string
    string longestCompleteString(vector<string>& words) {
        // Store all words in a set for quick lookup
        unordered_set<string> wordSet(words.begin(), words.end());
        string result = "";

        // Iterate over each word
        for (string& word : words) {
            bool isComplete = true;

            // Check all prefixes of the word
            for (int i = 1; i < word.length(); ++i) {
                if (wordSet.find(word.substr(0, i)) == wordSet.end()) {
                    isComplete = false;
                    break;
                }
            }

            // If complete and better than current result, update
            if (isComplete) {
                if (word.length() > result.length() || 
                   (word.length() == result.length() && word < result)) {
                    result = word;
                }
            }
        }

        // Return result or "None" if not found
        return result == "" ? "None" : result;
    }
};

int main() {
    vector<string> words = {"a", "ap", "app", "appl", "apple", "apply"};
    Solution sol;
    // cout << sol.longestCompleteString(words) << endl;
    return 0;
}

// Complexity Analysis
// Time Complexity: O(N * L²), we check every prefix (up to L) for N words, each prefix check can take up to O(L).
// Space Complexity: O(N * L), we store all N strings of average length L in a set.

// Optimal Approach
// The brute force approach becomes slow when the number of words is large or the words are long. To optimize this, we use a Trie. A Trie allows us to efficiently store all the words and check for prefixes while building the longest complete string. This avoids repeated scanning and checking of each prefix separately, making the process faster and more structured.
// Insert all the words into a Trie, and mark each end of a word during insertion.
// Now go through each word in the input list.
// For every word, check in the Trie if all its prefixes exist and are marked as complete words.
// If all prefixes are found, keep track of this word if it's longer or lexicographically smaller than the previously stored result.
// Return the longest complete string after checking all words. If none are found, return "None".
#include <bits/stdc++.h>
using namespace std;

// Class to represent each node of the Trie
class TrieNode {
public:
    // Indicates end of a valid word
    bool isEnd; 
    unordered_map<char, TrieNode*> children;

    TrieNode() {
        isEnd = false;
    }
};

// Class that contains only logic; no root stored
class Solution {
public:
    // Insert a word into the Trie
    void insert(TrieNode* root, string word) {
        // Start from the root
        TrieNode* node = root;

        // Traverse each character of the word
        for (char ch : word) {
            // If child for character doesn't exist, create a new node
            if (!node->children[ch])
                node->children[ch] = new TrieNode();

            // Move to the next node
            node = node->children[ch];
        }

        // Mark the end of the word
        node->isEnd = true;
    }

    // Check if all prefixes of a word are present in the Trie
    bool allPrefixesExist(TrieNode* root, string word) {
        // Start from the root
        TrieNode* node = root;

        // Check each character one by one
        for (char ch : word) {
            // Move to the next character node
            node = node->children[ch];

            // If node is missing or prefix not marked as word end, return false
            if (!node || !node->isEnd)
                return false;
        }

        // All prefixes exist
        return true;
    }

    // Find the longest complete string
    string longestCompleteString(TrieNode* root, vector<string>& words) {
        // Insert all words into the Trie
        for (string word : words)
            insert(root, word);

        string ans = "";

        // Check each word to see if it's a complete string
        for (string word : words) {
            if (allPrefixesExist(root, word)) {
                // Update if it's longer or 
               // lexicographically smaller than current answer
                if (word.length() > ans.length() || 
                 (word.length() == ans.length() && word < ans))
                    ans = word;
            }
        }

        // If no valid complete string found, return "None"
        return ans.empty() ? "None" : ans;
    }
};

// Driver code
int main() {
    // Create the root of the Trie
    TrieNode* root = new TrieNode();
    
    // Create a Solution object
    Solution sol;

    // List of input words
    vector<string> words = {"n", "ni", "nin", "ninj", "ninja", "ninga"};

    // Find and print the longest complete string
    cout << sol.longestCompleteString(root, words) << endl;

    return 0;
}

// Complexity Analysis
// Time Complexity: O(N * L), Where N is the number of words and L is the average length of each word.
// Space Complexity: O(N * L), for storing all characters of all words in the trie structure
