// Is Power of Two?
// Given an integer n, return true if it is a power of two. Otherwise, return false.
// An integer n is a power of two, if there exists an integer x such that n == 2^x.

// Example 1: n = 16;
// Now take n & n-1 for the answer
// Its because:
// n   => 10000
// n-1 => 01111
// Here if we perform &, we get the number 00000 => it means it is power of two

// Example 2: n = 40;
// Now take n & n-1 for the answer
// Its because: 
// n   => 101000
// n-1 => 100111
// Here if we perform &, we get the number 100000 => it means it is not a power of two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false; 
        return (n & (n - 1)) == 0;
    }
};