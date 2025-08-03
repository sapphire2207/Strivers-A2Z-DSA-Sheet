// Maximum Product Subarray in an Array
// Problem Statement: Given an array that contains both negative and positive integers, find the maximum product subarray.

// Example 1:
// Input:
//  Nums = [1,2,3,4,5,0]
// Output:
//  120
// Explanation:
//  In the given array, we can see 1×2×3×4×5 gives maximum product value.

// Brute Force Method:
// Find all possible subarrays of the given array. Find the product of each subarray. Return the maximum of all them.
// Following are the steps for the approach:-
// Run a loop on the array to choose the start point for each subarray.
// Run a nested loop to get the end point for each subarray.
// Multiply elements present in the chosen range.
#include<bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int>& nums) {
    int result = INT_MIN;
    for(int i=0;i<nums.size()-1;i++) {
        for(int j=i+1;j<nums.size();j++) {
            int prod = 1;
            for(int k=i;k<=j;k++) 
                prod *= nums[k];
            result = max(result,prod);    
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}

// Output: The maximum product subarray: 20

// Time Complexity: O(N3)
// Reason: We are using 3 nested loops for finding all possible subarrays and their product.
// Space Complexity: O(1)
// Reason: No extra data structure was used

// Better Approach:
// We can optimize the brute force by making 3 nested iterations to 2 nested iterations
// Following are the steps for the approach:
// Run a loop to find the start of the subarrays.
// Run another nested loop
// Multiply each element and store the maximum value of all the subarray.
#include<bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int>& nums) {
    int result = nums[0];
    for(int i=0;i<nums.size()-1;i++) {
        int p = nums[i];
        for(int j=i+1;j<nums.size();j++) {
           result = max(result,p);
           p *= nums[j];
        }
        result = max(result,p);//manages (n-1)th term 
    }
    return result;
}

int main() {
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}

// Output: The maximum product subarray: 20

// Time Complexity: O(N2)
// Reason: We are using two nested loops
// Space Complexity: O(1)
// Reason: No extra data structures are used for computation

// Optimal Approach 1:
// We will optimize the solution through some observations.
// Observations:
// If the given array only contains positive numbers: If this is the case, we can confidently say that the maximum product subarray will be the entire array itself.
// If the given also array contains an even number of negative numbers: As we know, an even number of negative numbers always results in a positive number. So, also, in this case, the answer will be the entire array itself.
// If the given array also contains an odd number of negative numbers: Now, an odd number of negative numbers when multiplied result in a negative number. Removal of 1 negative number out of the odd number of negative numbers will leave us with an even number of negatives. Hence the idea is to remove 1 negative number from the result. Now we need to decide which 1 negative number to remove such that the remaining subarray yields the maximum product.
// For example, the given array is: {3, 2, -1, 4, -6, 3, -2, 6}
// We will try to remove each possible negative number and check in which case the subarray yields the maximum product.
// Upon observation, we notice that each chosen negative number divides the array into two parts.
// The answer will either be the prefix or the suffix of that negative number.
// To find the answer, we will check all possible prefix subarrays (starting from index 0) and all possible suffix subarrays (starting from index n-1).
// The maximum product obtained from these prefix and suffix subarrays will be our final answer.
// If the array contains 0’s as well: We should never consider 0’s in our answer(as considering 0 will always result in 0) and we want to obtain the maximum possible product. So, we will divide the given array based on the location of the 0’s and apply the logic of case 3 for each subarray.

// For example, the given array is: {-2, 3, 4, -1, 0, -2, 3, 1, 4, 0, 4, 6, -1, 4}.
// In this case, we will divide the array into 3 different subarrays based on the 0’s locations. So, the subarrays will be {-2, 3, 4, -1}, {-2, 3, 1, 4}, and {4, 6, -1, 4}.
// In these 3 subarrays, we will apply the logic discussed in case 3. We will get 3 different answers for 3 different subarrays.
// The maximum one among those 3 answers will be the final answer.
// Summary: In real-life problems, we will not separate out the cases as we did in the observations. Instead, we can directly apply the logic discussed in the 4th observation to any given subarray, and it will automatically handle all the other cases.
#include <bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int> &arr) {
    int n = arr.size(); //size of array.

    int pre = 1, suff = 1;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (pre == 0) pre = 1;
        if (suff == 0) suff = 1;
        pre *= arr[i];
        suff *= arr[n - i - 1];
        ans = max(ans, max(pre, suff));
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, -3, 0, -4, -5};
    cout << "The maximum product subarray is: "
         << maxProductSubArray(arr) << "\n";
    return 0;
}

// Output: The maximum product subarray: 20

// Time Complexity: O(N), N = size of the given array.
// Reason: We are using a single loop that runs for N times.
// Space Complexity: O(1) as No extra data structures are used for computation.