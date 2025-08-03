// Count Good Numbers

// A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
// For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
// Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.
// A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

// Example 1:
// Input: n = 1
// Output: 5
// Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".

// Example 2:
// Input: n = 4
// Output: 400

// Example 3:
// Input: n = 50
// Output: 564908303

// Constraints:
// 1 <= n <= 1015

// Approach 1: Fast Exponentiation
// For the numbers at even indices, they can be 0,2,4,6,8, a total of 5 types. A digit string of length n has -((n + 1) / 2) even indices. For the numbers at odd indices, they can be 2,3,5,7, a total of 4 types. A digit string of length n has (n / 2) odd indices.
// Therefore, the total number of good numbers in a digit string of length n is:
// 5 ^ ((n + 1)/2) * 4 ^ (n /2)
// In this question, since the maximum value of n can reach 10 ^ 15, directly calculating the power in the formula using ordinary multiplication would exceed the time limit. Therefore, we need to use the fast exponentiation algorithm to optimize the calculation of the power.
// Complexity Analysis
// TC: O(logN)
// SC: O(1)
#define mod 1000000007
class Solution {
public:
    long long myPow(long long x, long long n) {
        long long result = 1;
        x %= mod;
        while (n > 0) {
            if (n % 2 == 1) {
                result = (result * x) % mod;
                n = n - 1;
            }
            else{
                x = (x * x) % mod;
                n /= 2;
            }
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long oddPlaces = n / 2;
        long long evenPlaces = n - oddPlaces;
        long long result = (myPow(5, evenPlaces) * myPow(4, oddPlaces)) % mod;
        return result;
    }
};
