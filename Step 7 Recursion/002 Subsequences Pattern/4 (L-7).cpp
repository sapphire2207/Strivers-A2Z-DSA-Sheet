// ## Pattern 1: Print all the possible subsequences of the Array whose sum is K

// Examples:
// Example 1:
// Input: arr = [1, 2, 1], sum = 2
// Output: [1,1], [2]
// Explanation: Printing all the subsequences from the array whose sum is 2.

// Solution 2: Using recursion (Backtracking)
// Intuition: We will explore all subsequences using pick and not-pick approach.
// While doing that, we maintain a running sum and print only those subsequences
// whose sum equals the given value K.

// Approach:
// We maintain a temporary vector (say ds) to store the current subsequence.
// We also maintain an integer (say s) to store the current sum.
// At each step, we can either pick the element or not pick the element:
// - If we pick, add arr[i] to ds and add its value to s.
// - If we don't pick, just move to the next index.
// When index reaches the end (i == n), check if s == target sum.
// If yes, print the current subsequence (ds).

#include<bits/stdc++.h>
using namespace std;

void solve(int i, int s, int k, vector<int>& arr, vector<int>& ds) {
	if (i == arr.size()) {
		if (s == k) {
			for (auto it : ds) cout << it << " ";
			cout << endl;
		}
		return;
	}

	// pick the current element
	ds.push_back(arr[i]);
	s += arr[i];
	solve(i + 1, s, k, arr, ds);
	
	// backtrack: remove the element and try not picking it
	s -= arr[i];
	ds.pop_back();

	// not pick the current element
	solve(i + 1, s, k, arr, ds);
}

int main() {
	vector<int> arr = {1, 2, 1};
	int k = 2;
	vector<int> ds;
	cout << "All subsequences whose sum is " << k << " are:" << endl;
	solve(0, 0, k, arr, ds);
}

// Output:
// All subsequences whose sum is 2 are:
// 1 1
// 2

// Time Complexity: O(2^n) - For each element, two choices (pick or not pick).
// Space Complexity: O(n) - Stack space + temporary vector ds.


// ## Pattern - 2: Print any one subsequence whose sum equals the given target.

// Example:
// arr = [1, 2, 1]
// sum = 2

// Approach:
// Use a boolean return type in the recursive function.
// In the base case, return true if the condition is satisfied, else return false.
// For each recursive call:
// If the "pick" call returns true, return immediately.
// If the "not pick" call returns true, return immediately.
// If both fail, return false.

#include <iostream>
#include <vector>
using namespace std;

bool printOneSubsequence(int index, vector<int> &arr, vector<int> &ds, int s, int sum) {
    // Base case: if we reach the end of the array
    if (index == arr.size()) {
        if (s == sum) {
            // Found a valid subsequence
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
            return true;
        }
        return false; // Not a valid subsequence
    }

    // Pick the element
    ds.push_back(arr[index]);
    s += arr[index];
    if (printOneSubsequence(index + 1, arr, ds, s, sum))
        return true;

    // Backtrack and not pick the element
    s -= arr[index];
    ds.pop_back();
    if (printOneSubsequence(index + 1, arr, ds, s, sum))
        return true;

    // If neither pick nor not-pick leads to the answer
    return false;
}

int main() {
    vector<int> arr = {1, 2, 1};
    vector<int> ds;
    int sum = 2;
    printOneSubsequence(0, arr, ds, 0, sum);
    return 0;
}

// Pattern 3: Given an array and an integer k, count how many subsequences of the array sum up to k.

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