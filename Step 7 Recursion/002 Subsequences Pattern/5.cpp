// Question 5: Given an array and an integer k, count how many subsequences of the array sum up to k.

// Approach:
// At each index, you can either pick the element or not pick it.
// If you reach the end (base case):
// If the current sum is equal to k, return 1.
// Else, return 0.
// Recursively explore both choices and sum their results.

#include <iostream>
#include <vector>
using namespace std;

// Recursive function to count subsequences whose sum is exactly k
int countSubsequences(int index, int currentSum, const vector<int>& arr, int k) {
    // Base Case: If we've considered all elements
    if (index == arr.size()) {
        // Check if the current sum equals the target sum k
        if (currentSum == k) return 1;
        return 0;
    }

    // Include the current element
    int left = countSubsequences(index + 1, currentSum + arr[index], arr, k);

    // Exclude the current element
    int right = countSubsequences(index + 1, currentSum, arr, k);

    // Return the total number of valid subsequences from both choices
    return left + right;
}

int main() {
    vector<int> arr = {1, 2, 1}; 
    int k = 2;                    

    int totalCount = countSubsequences(0, 0, arr, k);

    cout << "Total number of subsequences with sum " << k << " is: " << totalCount << endl;

    return 0;
}

// Output:
// Total number of subsequences with sum 2 is: 2