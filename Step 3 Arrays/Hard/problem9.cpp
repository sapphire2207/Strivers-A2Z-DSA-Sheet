// Find the repeating and missing numbers

// Problem Statement: You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

// Example 1:
// Input Format:  array[] = {3,1,2,5,3}
// Result: {3,4}
// Explanation: A = 3 , B = 4 
// Since 3 is appearing twice and 4 is missing

// Brute Force Approach
// Intuition: For each number between 1 to N, we will try to count the occurrence in the given array using linear search. And the element with occurrence as 2 will be the repeating number and the number with 0 occurrences will be the missing number.

#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size(); // size of the array
    int repeating = -1, missing = -1;

    //Find the repeating and missing number:
    for (int i = 1; i <= n; i++) {
        //Count the occurrences:
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] == i) cnt++;
        }

        if (cnt == 2) repeating = i;
        else if (cnt == 0) missing = i;

        if (repeating != -1 && missing != -1)
            break;
    }
    return {repeating, missing};
}

int main() {
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}

// Output: The repeating and missing numbers are: {5, 8}

// Time Complexity: O(N2), where N = size of the given array.
// Reason: Here, we are using nested loops to count occurrences of every element between 1 to N.
// Space Complexity: O(1) as we are not using any extra space.

// Better Approach
// Instead of counting the occurrences every time, using the hashing technique, we will store the frequency of each element between 1 to N. Now, the element with frequency 2 will be the repeating number and the element with frequency 0 will be the missing number.
// Note: Here, we can solve this problem using a hash array.
#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size(); // size of the array
    int hash[n + 1] = {0}; // hash array

    //update the hash array:
    for (int i = 0; i < n; i++) {
        hash[a[i]]++;
    }

    //Find the repeating and missing number:
    int repeating = -1, missing = -1;
    for (int i = 1; i <= n; i++) {
        if (hash[i] == 2) repeating = i;
        else if (hash[i] == 0) missing = i;

        if (repeating != -1 && missing != -1)
            break;
    }
    return {repeating, missing};
}

int main() {
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}

// Output: The repeating and missing numbers are: {5, 8}

// Time Complexity: O(2N), where N = the size of the given array.
// Reason: We are using two loops each running for N times. So, the time complexity will be O(2N).
// Space Complexity: O(N) as we are using a hash array to solve this problem.

// Optimal Approach 1:
// Intuition:
// The idea is to convert the given problem into mathematical equations. Since we have two variables i.e. missing and repeating, we will try to form two linear equations. And then we will find the values of two variables using those equations.
// Assume the repeating number to be X and the missing number to be Y.
// In the array, the numbers are between 1 to N, and in that range, one number is missing and one number is occurring twice.

// Step 1: Form equation 1:
// Now, we know the summation of the first N numbers is:
// Sn = (N*(N+1))/2
// Let’s say, S = the summation of all the elements in the given array.
// Therefore, S - Sn = X - Y…………………equation 1
// Step 2: Form equation 2:
// Now, we know the summation of squares of the first N numbers is:
// S2n = (N*(N+1)*(2N+1))/6
// Let’s say, S2 = the summation of squares of all the elements in the given array.
// Therefore, S2-S2n = X2-Y2...................equation 2
// From equation 2 we can conclude,
// X+Y = (S2 - S2n) / (X-Y) [From equation 1, we get the value X-Y] ………… equation 3
// From equation 1 and equation 3, we can easily find the value of X and Y. And this is what we want.
// Note: Here, we are summing all the numbers and squares of all the numbers, so we should use a bigger data type(Like in C++, long long instead of int).
#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    long long n = a.size(); // size of the array

    // Find Sn and S2n:
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    //S-Sn = X-Y:
    long long val1 = S - SN;

    // S2-S2n = X^2-Y^2:
    long long val2 = S2 - S2N;

    //Find X+Y = (X^2-Y^2)/(X-Y):
    val2 = val2 / val1;

    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // Here, X-Y = val1 and X+Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}

int main() {
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}

// Output: The repeating and missing numbers are: {5, 8}

// Time Complexity: O(N), where N = the size of the given array.
// Reason: We are using only one loop running for N times. So, the time complexity will be O(N).
// Space Complexity: O(1) as we are not using any extra space to solve this problem.

// Optimal Approach 2
// Using XOR, we are going to solve this problem using the following 3 steps.
// Assume the repeating number to be X and the missing number to be Y.
// Step 1: Find the XOR of the repeating number(X) and the missing number(Y)
// i.e. (X^Y) = (a[0]^a[1]^.....^a[n-1]) ^ (1^2^........^N)
// In order to find the XOR of the repeating number and the missing number, we will first XOR all the array elements and with that value, we will again XOR all the numbers from 1 to N.
// (X^Y) = (a[0]^a[1]^.....^a[n-1]) ^ (1^2^3^........^N)

// Step 2: Find the first different bit from right between the repeating and the missing number i.e. the first set bit from right in (X^Y)
// By convention, the repeating and the missing number must be different and since they are different they must contain different bits. Now, our task is to find the first different bit from the right i.e. the end. We know, the XOR of two different bits always results in 1. The position of the first different bit from the end will be the first set bit(from the right) in (X^Y) that we have found in step 1.

// Step 3: Based on the position of the different bits we will group all the elements ( i.e. all array elements + all elements between 1 to N) into 2 different groups
// Assume an imaginary array containing all the array elements and all the elements between 1 to N. Now, we will check that particular position for each element of that imaginary array and then if the bit is 0, we will insert the element into the 1st group otherwise, we will insert it into the 2nd group. 
// After performing this step, we will get two groups. Now, if we XOR all the elements of those 2 groups, we will get 2 numbers. One of them will be the repeating number and the other will be the missing number. But until now, we do not know which one is repeating and which one is missing.

// Last step: Figure out which one of the numbers is repeating and which one is missing
// We will traverse the entire given array and check which one of them appears twice. And the number that appears twice is the repeating number and the other one is the missing number.
#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size(); // size of the array

    int xr = 0;

    //Step 1: Find XOR of all elements:
    for (int i = 0; i < n; i++) {
        xr = xr ^ a[i];
        xr = xr ^ (i + 1);
    }

    //Step 2: Find the differentiating bit number:
    int number = (xr & ~(xr - 1));

    //Step 3: Group the numbers:
    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++) {
        //part of 1 group:
        if ((a[i] & number) != 0) {
            one = one ^ a[i];
        }
        //part of 0 group:
        else {
            zero = zero ^ a[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        //part of 1 group:
        if ((i & number) != 0) {
            one = one ^ i;
        }
        //part of 0 group:
        else {
            zero = zero ^ i;
        }
    }

    // Last step: Identify the numbers:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == zero) cnt++;
    }

    if (cnt == 2) return {zero, one};
    return {one, zero};
}

int main() {
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}

// Output: The repeating and missing numbers are: {5, 8}

// Time Complexity: O(N), where N = the size of the given array.
// Reason: We are just using some loops running for N times. So, the time complexity will be approximately O(N).
// Space Complexity: O(1) as we are not using any extra space to solve this problem.