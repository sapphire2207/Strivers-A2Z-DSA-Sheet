// Problem 12:- Rotate matrix by 90 degree in clockwise direction

// Brute Force Method:-
// Take another dummy matrix of n*n, and then take the first row of the matrix and put it in the last column of the dummy matrix, take the second row of the matrix, and put it in the second last column of the matrix and so.
// [0][0] --> [0][2]   [1][0] --> [0][1]
// [0][1] --> [1][2]   [1][1] --> [1][1]
// [0][2] --> [2][2]   [1][2] --> [2][1]
// ==> matrix[i][j] = answer[j][n-i-1]
// TC:- O(N*N)
// SC:- O(N*N)
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rotate(vector < vector < int >> & matrix) {
    int n = matrix.size();
    vector < vector < int >> rotated(n, vector < int > (n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotated[j][n - i - 1] = matrix[i][j];
        }
    }
    return rotated;
}

int main() {
    vector<vector<int>> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> rotated = rotate(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < rotated.size(); i++) {
        for (int j = 0; j < rotated[0].size(); j++) {
            cout << rotated[i][j] << " ";
        }
        cout << "n";
    }
}

// Optimal Method:-
// By observation, we see that the first column of the original matrix is the reverse of the first row of the rotated matrix, so that’s why we transpose the matrix and then reverse each row, and since we are making changes in the matrix itself space complexity gets reduced to O(1)
// TC:- O(N*N) + O(N*N).One O(N*N) is for transposing the matrix and the other is for reversing the matrix
// SC:- O(1)
#include<bits/stdc++.h>
using namespace std;

void rotatee(vector < vector < int >> & matrix) {
    int n = matrix.size();
    //transposing the matrix
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    //reversing each row of the matrix
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotatee(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
        cout << arr[i][j] << " ";
    }
    cout << "n";
    }
}