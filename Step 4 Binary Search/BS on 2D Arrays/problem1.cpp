// Find the row with maximum number of 1's

// Problem Statement: You have been given a non-empty grid ‘mat’ with 'n' rows and 'm' columns consisting of only 0s and 1s. All the rows are sorted in ascending order.
// Your task is to find the index of the row with the maximum number of ones.
// Note: If two rows have the same number of ones, consider the one with a smaller index. If there's no row with at least 1 zero, return -1.

// Example 1:
// Input Format: n = 3, m = 3, 
// mat[] = 
// 1 1 1
// 0 0 1
// 0 0 0
// Result: 0
// Explanation: The row with the maximum number of ones is 0 (0 - indexed).

// Brute Force Approach
// In the question, it is clearly stated that we should return -1 if the matrix does not contain any 1.
// The extremely naive approach is to traverse the matrix as usual using nested loops and for every single row count the number of 1’s. Finally, we will return the row with the maximum no. of 1’s. If multiple rows contain the maximum no. of 1’s we will return the row with the minimum index.
#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int cnt_max = 0;
    int index = -1;

    //traverse the matrix:
    for (int i = 0; i < n; i++) {
        int cnt_ones = 0;
        for (int j = 0; j < m; j++) {
            cnt_ones += matrix[i][j];
        }
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}

int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " <<
         rowWithMax1s(matrix, n, m) << '\n';
}

// Output: The row with maximum no. of 1's is: 0

// Time Complexity: O(n X m), where n = given row number, m = given column number.
// Reason: We are using nested loops running for n and m times respectively.
// Space Complexity: O(1) as we are not using any extra space.

// Optimal Approach
// We are going to use the Binary Search algorithm to optimize the approach.
// The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.
// We cannot optimize the row traversal but we can optimize the counting of 1’s for each row.
// Instead of counting the number of 1’s, we can use the following formula to calculate the number of 1’s:
// Number_of_ones = m(number of columns) - first occurrence of 1(0-based index).
// As, each row is sorted, we can find the first occurrence of 1 in each row using any of the following approaches:
// lowerBound(1) (ref: Implement Lower Bound)
// upperBound(0) (ref: Implement Upper Bound)
// firstOccurrence(1) (ref: First and Last Occurrences in Array)
// Note: Here, we are going to use the lowerBound() function to find the first occurrence. You can use the other methods as well.
#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int cnt_max = 0;
    int index = -1;

    //traverse the rows:
    for (int i = 0; i < n; i++) {
        // get the number of 1's:
        int cnt_ones = m - lowerBound(matrix[i], m, 1);
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}

int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " <<
         rowWithMax1s(matrix, n, m) << '\n';
}

// Output: The row with maximum no. of 1's is: 0

// Time Complexity: O(n X logm), where n = given row number, m = given column number.
// Reason: We are using a loop running for n times to traverse the rows. Then we are applying binary search on each row with m columns.
// Space Complexity: O(1) as we are not using any extra space.