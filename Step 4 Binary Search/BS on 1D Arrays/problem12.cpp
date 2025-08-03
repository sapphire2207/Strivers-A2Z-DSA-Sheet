// Problem 12:-
// Given an array of N integers. Every number in the array except one appears twice. Find the single number in the array.

// Brute Force Method:-
// A crucial observation to note is that if an element appears twice in a sequence, either the preceding or the subsequent element will also be the same. But only for the single element, this condition will not be satisfied.
// If arr[i] != arr[i-1] and arr[i] != arr[i+1]: If this condition is true for any element, arr[i], we can conclude this is the single element.
// Edge Cases:
// If n == 1: This means the array size is 1. If the array contains only one element, we will return that element only.
// If i == 0: This means this is the very first element of the array. The only condition, we need to check is: arr[i] != arr[i+1].
// If i == n-1: This means this is the last element of the array. The only condition, we need to check is: arr[i] != arr[i-1].
// TC:- O(N)
#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size(); //size of the array.
    if (n == 1) return arr[0];

    for (int i = 0; i < n; i++) {

        //Check for first index:
        if (i == 0) {
            if (arr[i] != arr[i + 1])
                return arr[i];
        }
        //Check for last index:
        else if (i == n - 1) {
            if (arr[i] != arr[i - 1])
                return arr[i];
        }
        else {
            if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
                return arr[i];
        }
    }

    // dummy return statement:
    return -1;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int ans = singleNonDuplicate(arr);
    cout << "The single element is: " << ans << "\n";
    return 0;
}


// Using Binary Search:-
// Here we need to identify the halves and then eliminate them accordingly. In addition to that, we need to check if the current element i.e. arr[mid] is the ‘single element’.
// How to check if arr[mid] i.e. the current element is the single element:
// If arr[mid] != arr[mid-1] and arr[mid] != arr[mid+1] --> If this condition is true for arr[mid], we can conclude arr[mid] is the single element.
// The above condition will throw errors in the following 3 cases:
// If the array size is 1.
// If ‘mid’ points to 0 i.e. the first index.
// If ‘mid’ points to n-1 i.e. the last index.
// So inculde the edge cases in the code
// Now when it comes to elimination:-
// we can clearly notice a striking distinction between the index sequences of the left and right halves of the single element in the array. 
// The index sequence of the duplicate numbers in the left half is always (even, odd). That means one of the following conditions will be satisfied if we are in the left half:
// If the current index is even, the element at the next odd index will be the same as the current element.
// Similarly, If the current index is odd, the element at the preceding even index will be the same as the current element.
// The index sequence of the duplicate numbers in the right half is always (odd, even). That means one of the following conditions will be satisfied if we are in the right half:
// If the current index is even, the element at the preceding odd index will be the same as the current element.
// Similarly, If the current index is odd, the element at the next even index will be the same as the current element.
// If we are in the left half of the single element, we have to eliminate this left half (i.e. low = mid+1). Because our single element appears somewhere on the right side.
// If we are in the right half of the single element, we have to eliminate this right half (i.e. high = mid-1). Because our single element appears somewhere on the left side.
// TC:- O(N)
#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size(); //size of the array.

    //Edge cases:
    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];
//        0  1  2  3  4  5  6  7  8  9  10    
// arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6}
// arr = {1, 1, 2, 3, 3, 4, 4, 5, 5, 6, 6}
    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if arr[mid] is the single element:
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
            return arr[mid];
        }

        //we are in the left:
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1])
                || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
            //eliminate the left half:
            low = mid + 1;
        }
        //we are in the right:
        else {
            //eliminate the right half:
            high = mid - 1;
        }
    }

    // dummy return statement:
    return -1;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int ans = singleNonDuplicate(arr);
    cout << "The single element is: " << ans << "\n";
    return 0;
}
