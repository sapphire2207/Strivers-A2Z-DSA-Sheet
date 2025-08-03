// Next Greater Element

// Problem Statement
// Given an array arr of size n, for each element, find the next greater element (NGE) on its right side. If there is no greater element, return -1.
// Input:  [6, 0, 8, 1, 3]
// Output: [8, 8, -1, 3, -1]

// Brute Force (O(n²))
// For each element, iterate through the remaining right-side elements.
// Find the first greater element.
// If no greater element exists, store -1.
// Time Complexity:
// O(N²) since for every element, we may have to scan all elements to the right.
// Space Complexity:
// O(N) - for returning the answer
#include<bits/stdc++.h>
using namespace std;

void nextGreaterElementBruteForce(vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n, -1);

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[j] > arr[i]){
                nge[i] = arr[j];
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " → " << nge[i] << endl;
    }
}

int main(){
    vector<int> arr = {4, 5, 2, 25, 7, 8};
    nextGreaterElementBruteForce(arr);
    return 0;
}

// Optimized Stack-Based Approach (O(N))
// This method uses a monotonic decreasing stack to find the next greater element efficiently.
// Traverse the array backward to ensure elements on the right are processed first.
// Use a stack to efficiently find the next greater element.
// Monotonic Stack Property: Stack maintains elements in decreasing order (i.e., smallest on top gets removed when a larger number comes).
// TC: O(2N) - one for iterating all elements.... other O(N) may be the pop operation in the worst case
// SC: O(N)
#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> NGE(n, -1); // Default result initialized to -1
    stack<int> s; // Monotonic stack

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Remove elements smaller than arr[i]
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        // if stack is empty and all smaller elements removed it means there's no greater element... therefore -1... or else the nge is the stack's top most element....
        if (s.empty()) {
            NGE[i] = -1;
        }
        else{
            NGE[i] = s.top();
        }
        
        // Push current element into stack
        s.push(arr[i]);
    }
    return NGE;
}

int main() {
    vector<int> arr = {6, 0, 8, 1, 3};
    vector<int> result = nextGreaterElement(arr);
    
    cout << "Next Greater Elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}