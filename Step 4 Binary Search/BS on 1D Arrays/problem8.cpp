// Problem 8:-
// Given an integer array arr of size N, sorted in ascending order (with distinct values) and a target value k. Now the array is rotated at some pivot point unknown to you. Find the index at which k is present and if k is not present return -1.

// Example 1:
// Input Format: arr = [4,5,6,7,0,1,2,3], k = 0
// Result: 4
// Explanation: Here, the target is 0. We can see that 0 is present in the given rotated sorted array, Thus, we get output as 4, which is the index at which 0 is present in the array.

// Example 2:
// Input Format: arr = [7,8,9,1,2,3,4,5,6] k = 1
// Result: 3
// Explanation: Here, the target is 1.We can see that 1 is present in the given rotated sorted array, Thus, we get output as 3, which is the index at which 1 is present in the array.

// Brute Force Method:-
// Linear Search:
// TC:- O(N)
#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& arr, int n, int k) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == k)
            return i;
    }
    return -1;
}

int main()
{
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = 9, k = 1;
    int ans = search(arr, n, k);
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";
    return 0;
}


// Optimal Method:-
// arr = [7,8,9,1,2,3,4,5,6] k = 8
// Here we can't just make one binary search check and tell where the required element is present, because here rotation takes place, e.g here arr[mid] => mid=4, arr[4]=2, so by comparing arr[mid] and target i.e 8>2 ==> according to BS the element will be placed in the right half, but here since the rotation happened so the element is on the left actually, so we can't just solely depend on one BS check
// So here we have to check which part of the array is sorted, left or right, and after that in this sorted part we have to check whether the target is present, if present then remove the unsorted part
// if not present, then eliminate the sorted part
// TC:- O(logN) 
#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& arr,int n,int k){
    int low=0,high=n-1;
    int target = k;
    while(low<=high){
        int mid=low+high/2;

        if(arr[mid]==target){
            return mid;
        }
        //if left part is sorted:
        if(arr[low]<=arr[mid]){
            // then check whether the target is present in it, if it does eliminate the unsorted, if not eliminate the sorted part
            if(arr[low]<=target && target<=arr[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        // if right part is sorted
        else{
            // then check whether the target is present in it, if it does eliminate the unsorted, if not eliminate the sorted part
            if(arr[mid]<=target && target<=arr[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
}

int main(){
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = 9, k = 1;
    int ans = search(arr, n, k);
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";
    return 0;
}
