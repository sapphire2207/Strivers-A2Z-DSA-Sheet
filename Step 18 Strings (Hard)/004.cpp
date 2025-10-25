// Rabin Karp Algorithm - Pattern Searching

// Problem Statement: Given a string text and a string pattern, implement the Rabin-Karp algorithm to find the starting index of all occurrences of pattern in text. If pattern is not found, return an empty list.
// Examples
// Input: text = "ababcabcababc", pattern = "abc"
// Output: [2, 5, 10]
// Explanation:  The pattern "abc" is found at indices 2, 5, and 10 in the text.

// Input: text = "hello", pattern = "ll"
// Output: [2]
// Explanation: The pattern "ll" is found at index 2 in the text.

// Rabin-Karp Algorithm
// Why do we use Rabin-Karp Algorithm?
// When we want to find a pattern in a large text, a naive approach compares each possible substring character by character. That’s slow for large texts and multiple patterns and will result in TLE.
// Instead of comparing strings directly, Rabin-Karp Algorithm converts them into numbers using a hash function. Ideally, two strings with the same hash are same. Using a smart hash function, we can update the hash value in constant time when we use sliding window technique to check for matching substrings.
// We still compare the actual characters even after a hash match because different strings can sometimes produce the same hash value. To ensure accuracy, whenever the hash of a substring in the text matches the pattern's hash, we perform a direct character-by-character comparison to confirm that the match is genuine.
// First, calculate a numeric hash for the pattern you are trying to find.
// Then, take the first part of the text (of the same length as the pattern) and calculate its hash.
// Compare this hash with the pattern's hash.
// If they are not the same, move to the next substring.
// If they are the same, then compare the actual characters of the substring and the pattern to confirm a real match. Sometimes, even if hash values of two strings might match, there's a possibility that the string might not be equal.
// Slide the window one character forward in the text and update the hash efficiently without redoing the whole calculation from scratch.
// Repeat the comparison process — check the new hash against the pattern’s hash, and if needed, do the character-by-character confirmation.
// Continue this sliding and checking process until you've examined all possible substrings in the text.
// Finally, collect all positions where a confirmed match was found.
#include <bits/stdc++.h>
using namespace std;

class KarpRabin {
private:
    const int PRIME = 101;

    double calculateHash(const string &str) {
        double hash = 0;
        for (int i = 0; i < str.length(); i++) {
            hash += str[i] * pow(PRIME, i);
        }
        return hash;
    }

    double updateHash(double prevHash, char oldChar, char newChar, int patternLength) {
        double newHash = (prevHash - oldChar) / PRIME;
        newHash = newHash + newChar * pow(PRIME, patternLength - 1);
        return newHash;
    }

public:
    void search(const string &text, const string &pattern) {
        int patternLength = pattern.length();
        double patternHash = calculateHash(pattern);
        double textHash = calculateHash(text.substr(0, patternLength));

        for (int i = 0; i <= text.length() - patternLength; i++) {
            if (textHash == patternHash) {
                if (text.substr(i, patternLength) == pattern) {
                    cout << "Pattern found at index " << i << endl;
                }
            }

            if (i < text.length() - patternLength) {
                textHash = updateHash(textHash, text[i], text[i + patternLength], patternLength);
            }
        }
    }
};

int main() {
    KarpRabin kr;
    string text = "abedabc";
    string pattern = "abc";
    kr.search(text, pattern);
    return 0;
}

// Complexity Analysis
// Time Complexity: O(n+m), where n is length of text string and m is length of pattern string. In worst case time complexity can be O(n*m) if there are frequent hash collisions.
// Space Complexity: O(1), the algorithm only uses a few variables for hashing and tracking positions.