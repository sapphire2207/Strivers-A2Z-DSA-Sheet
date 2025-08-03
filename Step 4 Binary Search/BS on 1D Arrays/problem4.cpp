// Problem 4:- Search insert position
// Problem Statement: You are given a sorted array arr of distinct values and a target value x. You need to search for the index of the target value in the array.

// Input Format: arr[] = {1,2,4,7}, x = 6
// Result: 3
// Explanation: 6 is not present in the array. So, if we will insert 6 in the 3rd index(0-based indexing), the array will still be sorted. {1,2,4,6,7}.

// We can solve this by using lower bound, because "lb" is the one which satisfies the condition arr[index]>=x, and it will give you the minimum index among the elements according to the given target

// Refer Problem 2:- (Lower Bound)
