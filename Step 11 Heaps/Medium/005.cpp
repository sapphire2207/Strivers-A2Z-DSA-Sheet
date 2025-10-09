// Replace elements by its rank in the array

// Problem Statement: Given an array of N integers, the task is to replace each element of the array by its rank in the array.

// Example 1:
// Input: 20 15 26 2 98 6
// Output: 4 3 5 1 6 2
// Explanation: When sorted,the array is 2,6,15,20,26,98. So the rank of 2 is 1,rank of 6 is 2,rank of 15 is 3 and so…

// Example 2:
// Input: 1 5 8 15 8 25 9
// Output: 1 2 3 5 3 6 4
// Explanation: When sorted,the array is 1,5,8,8,9,15,25. So the rank of 1 is 1,rank of 5 is 2,rank of 8 is 3 and so…

// Approach:
// Intuition: Sort the array and store the rank of the element in a map.
// Copy all the elements of the array in a dummy array.
// Sort the dummy array.
// Take a variable temp to calculate the rank of each element.Initially the value of temp is 1.
// Maintain a map to store the rank of each element.
// Now traverse through the dummy array,if element is previously not stored in map then store the value of element with the temp and then increament temp.
// Now traverse through the original array and print the rank of that corresponding element using map.
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n = 6;
	int arr[n] = {20, 15, 26, 2, 98, 6};
	map<int, int>mp;
	int temp = 1;
	int brr[n];
	for (int i = 0; i < n; i++) {
		brr[i] = arr[i];
	}
	sort(brr, brr + n);
	for (int i = 0; i < n; i++) {
		//if element is previously not store in the map
		if (mp[brr[i]] == 0) {
			mp[brr[i]] = temp;
			temp++;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << mp[arr[i]] << " ";
	}

}

// Output: 4 3 5 1 6 2

// Time Complexity:O(n)+O(nlogn)+O(n). O(n) for copying the elements from the original to the dummy array, O(nlogn) for sorting the dummy array, and O(n) for printing the ranks.
// Space Complexity:O(N+N), for using dummy array and hashmap.