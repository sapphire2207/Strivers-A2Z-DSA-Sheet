// Nearest Smaller Element

// Problem Statement
// You are given an array of integers.
// For every element in the array, you must find the nearest smaller element to the left.
// If there is no smaller element to the left, return -1.

// Example
// Input:  arr[] = {4, 5, 2, 2, 8}
// Output:       {-1, 4, -1,  2, 2}
// Explanation:
// 4 → No element to the left → -1
// 5 → 4 is smaller and nearest → 4
// 2 → No smaller element → -1
// 2 → The previous 2 is the nearest smaller → 2
// 8 → 2 is the nearest smaller → 2

// Brute Force Approach:
// Stand at each element arr[i].
// Look backwards (left side) to find the nearest smaller element.
// If found, store it; otherwise, store -1.
// Time Complexity:
// The outer loop runs n times.
// The inner loop runs up to n times in the worst case.
// Overall Time Complexity: O(n²)
// Space Complexity:
// O(n) for storing the output.
#include<bits/stdc++.h>
using namespace std;

vector<int> nearestSmallerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> NSE(n, -1); // Initialize with -1

    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] < arr[i]) {
                NSE[i] = arr[j];
                break; // Stop at the first smaller element
            }
        }
    }
    return NSE;
}

int main() {
    vector<int> arr = {4, 5, 2, 2, 8};
    vector<int> result = nearestSmallerElement(arr);
    
    for (int x : result) cout << x << " ";
    return 0;
}

// Optimal Approach:
// We must find the nearest smaller element efficiently.
// Using a stack, we can maintain a monotonically increasing order to keep track of potential candidates.
// The stack stores elements in increasing order from left to right.
// When a new element arrives, we pop elements from the stack until we find a smaller element.
// Time Complexity:
// Each element is pushed and popped at most once.
// The worst case is O(2n) ≈ O(n).
// Space Complexity:
// O(n) for the stack.
#include<bits/stdc++.h>
using namespace std;

vector<int> nearestSmallerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> NSE(n, -1); // Store the answer
    stack<int> st;          // Monotonic increasing stack

    for (int i = 0; i < n; i++) {
        // Remove elements larger or equal to arr[i]
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        // If stack is not empty, top is the nearest smaller element
        NSE[i] = st.empty() ? -1 : st.top();

        // Push the current element into the stack
        st.push(arr[i]);
    }

    return NSE;
}

int main() {
    vector<int> arr = {4, 5, 2, 2, 8};
    vector<int> result = nearestSmallerElement(arr);
    
    for (int x : result) cout << x << " ";
    return 0;
}
