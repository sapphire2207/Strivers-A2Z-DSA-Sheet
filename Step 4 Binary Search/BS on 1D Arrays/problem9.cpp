// Problem 9:- 
// Given an integer array arr of size N, sorted in ascending order (may contain duplicate values) and a target value k. Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False.

// Example 1:
// Input Format: arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 3
// Result: True
// Explanation: The element 3 is present in the array. So, the answer is True.

// Example 2:
// Input Format: arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 10
// Result: False
// Explanation: The element 10 is not present in the array. So, the answer is False.

// Optimal Method:-
// In addition to the previous approach we have used, we should be aware of a edge case where the array might be:
// [3,1,2,3,3,3,3], here we will find difficulty in where the sorted part is present
// So here in this approach, we first check if arr[mid] is the target before identifying the sorted half. If arr[mid] is not our target, we encounter this edge case. In this scenario, since arr[mid] = arr[low] = arr[high], it means that neither arr[low] nor arr[high] can be the target. To handle this edge case, we simply remove arr[low] and arr[high] from our search space, without affecting the original algorithm. 
// To eliminate elements arr[low] and arr[high], we can achieve this by simply incrementing the low pointer and decrementing the high pointer by one step. We will continue this process until the condition arr[low] = arr[mid] = arr[high] is no longer satisfied.
// TC:- O(logN) for the best and average case.
// In the worst-case scenario, where all array elements are the same but not the target 
// (e.g., given array = {3, 3, 3, 3, 3, 3, 3}), we continue to reduce the search space by adjusting the low and high pointers until they intersect. This worst-case situation incurs a time complexity of O(N/2).
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

        // Edge case
        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            low++;
            high--;
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
