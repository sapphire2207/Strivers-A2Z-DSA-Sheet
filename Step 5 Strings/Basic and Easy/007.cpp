// Check if two Strings are anagrams of each other

// Problem Statement: Given two strings, check if two strings are anagrams of each other or not.

// Example 1:
// Input: CAT, ACT
// Output: true
// Explanation: Since the count of every letter of both strings are equal.

// Example 2:
// Input: RULES, LESRT 
// Output: false
// Explanation: Since the count of U and T  is not equal in both strings.

// Brute Force:
// Approach: Sort both the string and compare each and every letter of both strings. If all letters matched then, print true. Otherwise, print false.
// For Eg. 
// We have 
// Str1 = “INTEGER”
// Str2=”TEGERNI”
// After sorting Str1 and Str2, we find that both of the strings are
// Str1 =” EEGINRT”
// Str2=” EEGINRT”
// Since both of the strings are the same, this means both Str1 and Str2 are anagrams of each other.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for(int i = 0; i < s.size(); i++){
            if(s[i] != t[i]) return false;
        }
        return true;
    }
};

// Time Complexity: O(nlogn) since sorting function requires nlogn iterations.
// Space Complexity: O(1)

// Optimal:
// Just count the frequency of every element in Str1 and iterate through Str2 and decrease the count of every element in the frequency array. Now iterate again, if the frequency at any point is not 0 this means, strings are not anagrams of each other.
// For Eg, 
// Str1 = ”INTEGER”
// Str2 = ”NTEGERI”
// Frequency array of every element :
// We check for every element of Str2 and find that all elements are found, so return true.
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> count(26, 0);

        for(int i = 0; i < s.size(); i++){
            count[s[i] - 'a']++;
        }

        for(int i = 0; i < t.size(); i++){
            count[t[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++){
            if(count[i] != 0) return false;
        }
        return true;
    }
};

// Time Complexity: O(n) where n is the length of string
// Space Complexity: O(1) 