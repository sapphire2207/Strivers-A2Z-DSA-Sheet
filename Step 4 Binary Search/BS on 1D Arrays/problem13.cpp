// Problem 13:- 
// Given an array of length N. Peak element is defined as the element greater than both of its neighbors. Formally, if ‘arr[i]’ is the peak element, ‘arr[i – 1]’ < ‘arr[i]’ and ‘arr[i + 1]’ < ‘arr[i]’. Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.
// For the first element, the previous element should be considered as negative infinity as well as for the last element, the next element should be considered as negative infinity.
// To solve this problem, it's better to understand with a peak diagram

// Brute Force Method:-
// Perfrom a linear search and be careful with the edge cases
#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &arr) {
    int n = arr.size(); //Size of array.

    for (int i = 0; i < n; i++) {
        //Checking for the peak:
        if ((i == 0 || arr[i - 1] < arr[i]) && (i == n - 1 || arr[i] > arr[i + 1])) {
            return i;
        }
    }
    // Dummy return statement
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = findPeakElement(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;
}

// Optimal Method:-
// Perform normal BS and eliminate edge cases, after eliminating the edge cases reinitialized the low and high values, and now we should eliminate one of the halves to reach the peak element, So to identify the halves:
// The left half of the peak element has an increasing order. This means for every index i, arr[i-1] < arr[i].
// The right half of the peak element has a decreasing order. This means for every index i, arr[i+1] < arr[i].
// If we are in the left half of the peak element, we have to eliminate this left half (i.e. low = mid+1). Because our peak element appears somewhere on the right side.
// If we are in the right half of the peak element, we have to eliminate this right half(i.e. high = mid-1) Because our peak element appears somewhere on the left side.
// While handling this same piece of code, we can solve the problem when there exists multiple peaks, Generally there may be:
// The index is a common point where a decreasing sequence ends and an increasing sequence begins.
// The index might be on the left half.
// The index might be the peak itself.
// The index might be on the right half.
// In the code written till now, we were able to handle the last 3 possibilities, 
// If an index is a common point where a decreasing sequence ends and an increasing sequence begins, we can actually eliminate either the left or right half. Because both halves of such an index contain a peak.
// TC:- O(logN)
#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &arr) {
    int n = arr.size(); //Size of array.

    // Edge cases:
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        //If arr[mid] is the peak:
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]){
            return mid;
        }
        // If we are in the left:
        else if(arr[mid]>arr[mid-1]){
            low=mid+1;
        }
        // If we are in the right:
        else if(arr[mid]>arr[mid+1]){
            high=mid-1;
        }
        // Or, arr[mid] is a common point:
        else{
            low=mid+1;
         // high=mid-1; we can eliminate any one of the halves
        }
    }
    // Dummy return statement
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = findPeakElement(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;
}
