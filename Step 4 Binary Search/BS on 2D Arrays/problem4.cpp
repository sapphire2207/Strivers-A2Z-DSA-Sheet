// Find Peak Element-II | Binary Search

// Problem Statement: You are given a 0-indexed 2-D grid ‘g’ of size ‘n’ X ‘m’, where each cell contains a positive integer, and adjacent cells are distinct.
// You need to find the location of a peak element in it. If there are multiple answers, find any of them.
// A peak element is a cell with a value strictly greater than all its adjacent cells.
// Assume the grid to be surrounded by a perimeter of ‘-1s’.

// What is a peak element in a 2D matrix?
// A peak element in a 2D matrix refers to an element(say, matrix[i][j]) that is strictly greater than its four adjacent elements i.e. matrix[i-1][j], matrix[i+1][j], matrix[i][j-1], and matrix[i][j+1].
// Note: It is clearly stated in the question if any of its four adjacent elements does not exist, we can consider it as -1.
// For e.g. in the following matrix, the element 9 at cell (1, 1) is a peak element.
// The element, 9, is greater than all its four adjacent elements.
// Note: There can be multiple peak elements in a 2D matrix. Our goal is to find any one of them.

// Brute Force Approach
// The extremely naive approach is to check every possible cell of the given matrix and check if it is greater than all its four adjacent elements.

#include<bits/stdc++.h>
using namespace std;

vector<int> findPeakGrid(vector<vector<int>> &g) {
    int n = g.size(), m = g[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //check all 4 adjacent elements:
            if (i - 1 >= 0 && g[i][j] <= g[i - 1][j]) continue;
            if (i + 1 < n && g[i][j] <= g[i + 1][j]) continue;
            if (j - 1 >= 0 && g[i][j] <= g[i][j - 1]) continue;
            if (j + 1 < m && g[i][j] <= g[i][j + 1]) continue;
            return {i, j};
        }
    }
    //dummy return statement:
    return { -1, -1};
}

int main() {
    vector<vector<int>> g = {{8, 6}, {10, 1}};
    vector<int> ans = findPeakGrid(g);
    cout << "The peak element is at: {" << ans[0] << ", "
            << ans[1] << "}" << endl;
    return 0;
}

// Output: The peak element is at: {1, 0}

// Time Complexity: O(NXMX4) ~ O(NXM), where N = no. of rows and M = no. of columns.
// Reason: In order to traverse the matrix, we are using nested loops running for n and m times respectively. For every cell, we are checking four adjacent elements.
// Space Complexity: O(1) as we are not using any extra space.

// Optimized Brute-force Approach
// We can optimize the previous approach a bit with the observation that the largest element in the matrix will always be one of the peak elements. So, we can always return the largest element of the matrix as the answer

#include<bits/stdc++.h>
using namespace std;

vector<int> findPeakGrid(vector<vector<int>> &g) {
    int n = g.size(), m = g[0].size();
    int row = -1, col = -1;
    int ele = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] > ele) {
                ele = g[i][j];
                row = i;
                col = j;
            }
        }
    }
    return {row, col};
}

int main() {
    vector<vector<int>> g = {{8, 6}, {10, 1}};
    vector<int> ans = findPeakGrid(g);
    cout << "The peak element is at: {" << ans[0] << ", "
            << ans[1] << "}" << endl;
    return 0;
}

// Output: The peak element is at: {1, 0}

// Time Complexity: O(NXM), where N = no. of rows and M = no. of columns.
// Reason: In order to traverse the matrix to find the largest element, we are using nested loops running for n and m times respectively.
// Space Complexity: O(1) as we are not using any extra space.

// Optimal Approach
// Until now, we have figured out an algorithm that finds the peak element just by checking every element of the given 2D matrix. Now, if we wish to further optimize the approach we cannot afford to check every element. So, we have to eliminate some parts to reduce the time complexity. This is where the binary search algorithm comes in.
// The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.
// How to choose a range to apply binary search?
// In this scenario, we'll employ binary search within the columns of the matrix. Since the peak element is guaranteed to exist in one of the columns, our search range will span from 0 to M, where M represents the total number of columns.
// Until now, we have found where to apply binary search. However since binary search works by reducing the search space by half, we have to find a way to identify the halves and then eliminate them accordingly
// Observation:
// For an element, matrix[i][j], to be considered a peak element, it should surpass all four of its neighboring elements: matrix[i-1][j], matrix[i+1][j], matrix[i][j-1], and matrix[i][j+1]. To identify a peak element, we employ binary search along the columns of the matrix. On closer examination, within a given column, the largest element holds the highest potential for being the peak element.
// Thus by choosing the largest element of a particular row, we can eliminate the checking of the elements, matrix[i-1][j] and matrix[i+1][j].
// Now we just need to check the left and the right neighbors. And based on that checking only, we will eliminate the left or the right part.
// How to identify the halves accordingly:
// If we try to plot a graph with a row of the matrix, it will be like the following:
// Note: The red points denote the element matrix[i][j].
// If matrix[i][j] < matrix[i][j-1]: we are in the right half of the peak
// If matrix[i][j] < matrix[i][j+1]: we are in the left half of the peak.
// How to eliminate the halves accordingly:
// If we are in the left half of the peak element, we have to eliminate this left half (i.e. low = mid+1). Because our peak element appears somewhere on the right side.
// If we are in the right half of the peak element, we have to eliminate this right half (i.e. high = mid-1). Because our peak element appears somewhere on the left side.
// Why we are considering the largest element of a particular?
// Although every element of the selected column might be a peak element, the largest number has always the highest possibility of being one. That is why, to reduce the checking operation, we are selecting the largest number.
// How the elimination of halves is working?
// For example, if matrix[i][j-1] is greater than the chosen largest element matrix[i][j], we can conclude that matrix[i][j-1] is also greater than all the elements of the j-th column. This is because matrix[i][j] is the largest element of j-th column. Thus matrix[i][j-1] is now more likely to be the peak element. The logic is also applied to matrix[i][j+1]. This is how the elimination is working.

#include<bits/stdc++.h>
using namespace std;

int findMaxIndex(vector<vector<int>> &g, int n, int m, int col) {
    int maxValue = -1;
    int index = -1;
    //find the max element:
    for (int i = 0; i < n; i++) {
        if (g[i][col] > maxValue) {
            maxValue = g[i][col];
            index = i;
        }
    }
    return index;
}

vector<int> findPeakGrid(vector<vector<int>> &g) {
    int n = g.size(), m = g[0].size();

    //apply binary search:
    int low = 0, high = m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int maxRowIndex = findMaxIndex(g, n, m, mid);
        int left = mid - 1 >= 0 ? g[maxRowIndex][mid - 1] : -1;
        int right = mid + 1 < m ? g[maxRowIndex][mid + 1] : -1;

        if (g[maxRowIndex][mid] > left && g[maxRowIndex][mid] > right) {
            //location of peak element:
            return {maxRowIndex, mid};
        }
        else if (g[maxRowIndex][mid] < left) high = mid - 1;
        else low = mid + 1;
    }
    //dummy return statement:
    return { -1, -1};
}

int main() {
    vector<vector<int>> g = {{8, 6}, {10, 1}};
    vector<int> ans = findPeakGrid(g);
    cout << "The peak element is at: {" << ans[0] << ", "
            << ans[1] << "}" << endl;
    return 0;
}

// Output: The peak element is at: {1, 0}

// Time Complexity: O(N X logM), where N = number of rows, M = no. of columns.
// Reason: We are applying binary search along the columns and for each column we are finding the largest element which takes O(N) time complexity.
// Space Complexity: O(1) as we are not using any extra space.