// Problem statement: Given an array, we have found the number of occurrences of each element in the array.

// Example :
// Input: arr[] = {10,5,10,15,10,5};
// Output: 10  3
// 	       5   2
//         15  1
// Explanation: 10 occurs 3 times in the array
// 	            05 occurs 2 times in the array
//              15 occurs 1 time in the array


// Optimal Approach:
// Intuition: We can use a map of value and frequency pair, in which we can easily update the frequency of an element if it is already present in the map, if it is not present in the map then insert it in the map with frequency as 1. After completing all the iterations, print the value frequency pair. 

// TC: O(N) - worst case (since unordered map is used)
// SC: O(N)
#include <bits/stdc++.h>
using namespace std;
 
void Frequency(int arr[], int n)
{
    unordered_map<int, int> map;
 
    for (int i = 0; i < n; i++)
        map[arr[i]]++;
 
    // Traverse through map and print frequencies
    for (auto x : map)
        cout << x.first << " " << x.second << endl;
}
 
int main()
{
    int arr[] = {10,5,10,15,10,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Frequency(arr, n);
    return 0;
}