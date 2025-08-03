// Number of Substrings Containing All Three Characters
// Given a string s consisting only of characters a, b and c.
// Return the number of substrings containing at least one occurrence of all these characters a, b and c.
// Example 1:
// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

// Brute Force Solution
// Generate all possible substrings.
// Check if each substring contains 'a', 'b', and 'c'.
// TC: O(N*N)
// SC: O(3)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            vector<int> mpp(3,0);
            for(int j = i; j < n; j++){
                mpp[s[j] - 'a'] = 1;
                if(mpp[0] + mpp[1] + mpp[2] == 3){
                    count = count + 1;
                }
            }
        }
        return count;
    }
};

// Better Solution:
// Since if we get any substring... then the characters after that will also generate substrings... so just break out and add the number of substrings by finding (size - jth index)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            vector<int> mpp(3,0);
            for(int j = i; j < n; j++){
                mpp[s[j] - 'a'] = 1;
                if(mpp[0] + mpp[1] + mpp[2] == 3){
                    count = count + (n - j);
                    break;
                }
            }
        }
        return count;
    }
};

// Optimal Solution:
// Here the approach is: for every character, there is a substring that ends.... 
// i.e for every character you are iterating... first find the minimum possible window.... if you find the minimum possible then the characters before the window will also generate the substrings... 
// Use a hashmap (or array of size 3) to store the last seen index of 'a', 'b', and 'c'.
// Iterate with a right pointer (right), updating the latest index of the character.
// Once all three characters are present, the valid substring count is (min_index + 1), where min_index is the earliest occurrence among 'a', 'b', and 'c'.
// Input: s = "abcabc"
// TC: O(N)
// SC: O(1)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int count = 0;
        vector<int> lastSeen(3, -1);
        for(int i = 0; i < n; i++){
            lastSeen[s[i] - 'a'] = i;
            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
                count = count + 1 + min(min(lastSeen[0], lastSeen[1]), lastSeen[2]);
            }
        }
        return count;
    }
};