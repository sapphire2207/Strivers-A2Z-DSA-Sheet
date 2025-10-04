// Reverse Words in a String

// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

// Example 1:
// Input: s = "the sky is blue"
// Output: "blue is sky the"

// Example 2:
// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.

// Example 3:
// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

// Brute Force:
// Intuition:
// We just need to print the words in reverse order. If we can somehow store them in reverse order of their occurrence, then we can simply add them back to form the final string.
// Approach:
// Traverse the string character by character.
// Keep collecting characters to form a word.
// Whenever a space is found, push the formed word into a stack and reset the word.
// At the end, push the last word if it exists.
// Now, pop words from the stack one by one and append them to the answer string.
// While appending, add spaces between words (but not after the last one).
// This way, the stack automatically ensures that the words come out in reverse order.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string word = "";
        stack<string> st;
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                word += s[i];
            }
            else {
                if (!word.empty()) {
                    st.push(word);
                    word = "";
                }
            }
        }
        if (!word.empty()) st.push(word);
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
            if (!st.empty()) ans += " ";
        }
        return ans;
    }
};

// Time Complexity: O(N), Traversing the entire string
// Space Complexity: O(N), Stack and ans variable

// Optimal Solution
// Intuition:
// Instead of storing all the words first, we can directly build the result by scanning the string from the end. This way, we naturally encounter words in reverse order and can append them straight to our answer.
// Approach:
// Start traversing the string from the last character to the first.
// Collect characters into a temporary word until a space is found.
// When a space is encountered, check if a word was formed:
// If yes, append it to the answer string (add a space before if the answer isn’t empty).
// Reset the word.
// After the loop ends, check if a last word exists and append it similarly.
// Finally, return the constructed answer.
// This avoids using extra data structures like a stack since we handle the reversal during traversal itself.
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string word = "";
        string ans = "";

        for(int i = n - 1; i >= 0; i--){
            if(s[i] != ' '){
                word = s[i] + word;
            }
            else{
                if(!word.empty()){
                    if(!ans.empty()) ans += " ";
                    ans += word;
                    word = "";
                }
            }
        }

        if(!word.empty()){
            if(!ans.empty()) ans += " ";
            ans += word;
        }

        return ans;
    }
};

// Time Complexity: O(N), N~length of string
// Space Complexity: O(1), Constant Space