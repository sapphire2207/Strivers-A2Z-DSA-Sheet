// Generate all binary strings of length n

// Problem Statement:
// Generate all binary strings of length n.

// For example, for n = 2:
// 00
// 01
// 10
// 11

// Approach 1: Brute-force (Using Loops and Bitmasking)
// Intuition:
// There are 2^n binary strings of length n.
// We iterate from 0 to 2^n - 1 and convert each number into its binary representation of length n.
// Dry Run for n = 2:
// n = 2
// total = 1 << 2 = 4
// Loop runs for i = 0 to 3
// i = 0:
// bitset<32> b(0) → "00000000000000000000000000000000"
// b.to_string().substr(30) → "00"
// Output: 00
// i = 1:
// bitset<32> b(1) → "00000000000000000000000000000001"
// b.to_string().substr(30) → "01"
// Output: 01
// i = 2:
// bitset<32> b(2) → "00000000000000000000000000000010"
// b.to_string().substr(30) → "10"
// Output: 10
// i = 3:
// bitset<32> b(3) → "00000000000000000000000000000011"
// b.to_string().substr(30) → "11"
// Output: 11
// Time Complexity:
// O(2^n * n)
// Each of 2^n iterations prints a string of size n.
// Space Complexity:
// O(n) per string

#include<bits/stdc++.h>
using namespace std;

void generateBinaryBrute(int n) {
    int total = 1 << n; 
    for (int i = 0; i < total; ++i) {
        bitset<32> b(i); 
        string binary = b.to_string().substr(32 - n);
        cout << binary << endl;
    }
}

// Approach 2: Better (Using Recursion)
// Intuition:
// Build the binary string character-by-character using recursion:
// At each step, you can either add '0' or '1'.
// Dry Run for n = 2:
// Start with empty ""
// → Add '0' → "0"
//   → Add '0' → "00"
//   → Add '1' → "01"
// → Add '1' → "1"
//   → Add '0' → "10"
//   → Add '1' → "11"
// Time Complexity:
// O(2^n) calls
// Each call does O(n) work in copying string → total O(n * 2^n)
// Space Complexity:
// Stack depth O(n)

void generateBinaryRecursion(string s, int n) {
    if (s.length() == n) {
        cout << s << endl;
        return;
    }
    generateBinaryRecursion(s + "0", n);
    generateBinaryRecursion(s + "1", n);
}

void generateBinaryBetter(int n) {
    generateBinaryRecursion("", n);
}

int main() {
    int n = 3;
    cout << "Brute:\n";
    generateBinaryBrute(n);
    cout << "\nBetter:\n";
    generateBinaryBetter(n);
    return 0;
}
