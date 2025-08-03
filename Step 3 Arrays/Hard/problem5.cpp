// Length of the longest subarray with zero Sum

// Problem Statement: Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.

// Example 1:
// Input Format: N = 6, array[] = {9, -3, 3, -1, 6, -5}
// Result: 5
// Explanation: The following subarrays sum to zero:
// {-3, 3} , {-1, 6, -5}, {-3, 3, -1, 6, -5}
// Since we require the length of the longest subarray, our answer is 5!

// Brute Force Approach
// We are required to find the longest subarray that sums to zero. So our initial approach could be to consider all possible subarrays of the given array and check for the subarrays that sum to zero. Among these valid subarrays (a sum equal to zero) we’ll return the length of the largest subarray by maintaining a variable, say max. 

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& a) {
    int n = a.size();
    int maxLen = 0;

    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i ; j < n; j++){
            sum += a[j];
            if(sum == 0){
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}

int main() {
    vector<int> a = {9, -3, 3, -1, 6, -5};
    cout << solve(a) << endl;

    return 0;
}

// Output: 5

// Time Complexity: O(N^2) as we have two loops for traversal
// Space Complexity: O(1) as we aren’t using any extra space.

// Optimal Approach:
// Now let’s say we know that the sum of subarray(i, j) = S, and we also know that the sum of subarray(i, x) = S where i < x < j. We can conclude that the sum of subarray(x+1, j) = 0.
// Let us understand the above statement clearly,
// So in this problem, we’ll store the prefix sum of every element, and if we observe that 2 elements have the same prefix sum, we can conclude that the 2nd part of this subarray sums to zero
// Now let’s understand the approach
// First, let us initialize a variable say sum = 0 which stores the sum of elements traversed so far and another variable says max = 0 which stores the length of the longest subarray with sum zero.
// Declare a HashMap<Integer, Integer> which stores the prefix sum of every element as a key and its index as a value.
// Now traverse the array, and add the array element to our sum. 
//  (i)  If sum = 0, then we can say that the subarray until the current index has a sum = 0,      so we update max with the maximum value of (max, current_index+1)
// (ii)  If the sum is not equal to zero then we check the hashmap if we’ve seen a subarray with this sum before
// if HashMap contains sum -> this is where the above-discussed case occurs (subarray with equal sum), so we update our max 
// else -> Insert (sum, current_index) into hashmap to store prefix sum until the current index
// After traversing the entire array our max variable has the length of the longest substring having a sum equal to zero, so return max.
// NOTE: we do not update the index of a sum if it’s seen again because we require the length of the longest subarray
int maxLen(int A[], int n) {
    // Your code here
    unordered_map<int,int> mpp; 
    int maxi = 0;
    int sum = 0; 
    for(int i = 0;i<n;i++) {
        sum += A[i]; 
        if(sum == 0) {
            maxi = i + 1; 
        }
        else {
            if(mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]); 
            }
            else {
                mpp[sum] = i;
            }
        }   
    }

    return maxi; 
}

// Output: 3

// Time Complexity: O(N), as we are traversing the array only once
// Space Complexity: O(N), in the worst case we would insert all array elements prefix sum into our hashmap