// Sort characters by frequency

// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
// Return the sorted string. If there are multiple answers, return any of them.

// Example 1:
// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

// Example 2:
// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
// Note that "cacaca" is incorrect, as the same characters must be together.

// Example 3:
// Input: s = "Aabb"
// Output: "bbAa"
// Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.

// Constraints:
// 1 <= s.length <= 5 * 105
// s consists of uppercase and lowercase English letters and digits.

// Optimal:
// The goal is to rank characters based on how frequently they appear in the string.
// We need a structure that can track both the character and how often it occurs.
// Sorting the characters by frequency helps surface the most significant ones first.
// To maintain consistency when frequencies match, tie-breaking is done alphabetically.
// Once sorted, the characters with non-zero occurrences form the final ranked result.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        vector<pair<int, char>> vec;
        for (auto &it : freq) vec.push_back({it.second, it.first});

        sort(vec.begin(), vec.end(), [](auto &p1, auto &p2) {
            if (p1.first != p2.first) return p1.first > p2.first;
            return p1.second < p2.second;
        });

        string ans = "";
        for (auto &p : vec) ans.append(p.first, p.second);
        return ans;
    }
};

// Time Complexity: O(n + k log k), where n = s.length() and k = number of distinct characters in s (≤ 62).  Practical complexity is O(n) because k is small.
// Space Complexity: O(n + k), where O(k) is for frequency map and vector, and O(n) is for the output string.
