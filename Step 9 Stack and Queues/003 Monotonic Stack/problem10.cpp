// Remove K Digits

// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.
// Example 1:
// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

// Optimal Approach:
// The idea is to maintain a monotonic increasing stack to ensure that smaller digits are kept at the beginning while larger digits are removed.
// Intuition:
// To get the smallest number, we should remove larger digits first.
// If a larger digit appears before a smaller digit, removing the larger digit reduces the value of the number.
// The stack helps track digits and ensures we remove the largest possible ones first.
// TC: O(3N + K)
// SC: O(N) + O(N)
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string removeKdigits(string num, int k) {
            int n = num.size();
            stack<char> st;
            for(int i = 0; i < n; i++){
                while(!st.empty() && k > 0 && (st.top() - '0') > (num[i] - '0')){
                    st.pop();
                    k--;
                }
                st.push(num[i]);
            }
    
            while(k > 0 && !st.empty()){
                st.pop();
                k--;
            }
    
            if(st.empty()){
                return "0";
            }
    
            string result = "";
            while (!st.empty()) {
                result.push_back(st.top());
                st.pop();
            }
    
            while(result.size() != 0 && result.back() == '0'){
                result.pop_back();
            }
    
            reverse(result.begin(), result.end());
            if(result.empty()){
                return "0"; 
            }
            return result;
        }
    };