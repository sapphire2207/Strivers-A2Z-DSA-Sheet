// Maximum Sum Combination

// Problem Statement: Given two integer arrays nums1 and nums2 and an integer k, return the maximum k valid sum combinations from all possible sum combinations using the elements of nums1 and nums2. A valid sum combination is made by adding one element from nums1 and one element from nums2. Return the answer in non-increasing order.

// Examples
// Input : nums1 = [7, 3], nums2 = [1, 6], k = 2
// Output : [13, 9]
// Explanation : The 2 maximum combinations are made by: nums1[0] + nums2[1] = 13 nums1[1] + nums2[1] = 9 

// Input : nums1 = [3, 4, 5], nums2 = [2, 6, 3], k = 2 
// Output : [11, 10] 
// Explanation : The 2 maximum combinations are made by: nums1[2] + nums2[1] = 11 nums1[1] + nums2[1] = 10 

// Brute force Approach
// We are given two integer arrays and asked to find the top k largest pairwise sums, where each pair is formed by picking one element from each array. In the brute force approach, we can simply generate all possible pair sums. Then sort the resulting list in descending order. Finally, return the first k elements. This approach is easy to implement but very inefficient when both arrays are large.
// Initialize an empty list to store pairwise sums.
// Iterate over every element in the first array.
// For each element in the first array, iterate over every element in the second array.
// For each pair, calculate the sum and store it in the list.
// After generating all combinations, sort the list in descending order.
// Return the first k elements from the sorted list.

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Function to return the k largest valid sum combinations
    vector<int> maxCombinations(vector<int>& nums1, vector<int>& nums2, int k) {

        // List to store all possible pair sums
        vector<int> allSums;

        // Loop over every element in nums1
        for (int i = 0; i < nums1.size(); i++) {

            // Loop over every element in nums2
            for (int j = 0; j < nums2.size(); j++) {

                // Compute the pair sum and store it
                allSums.push_back(nums1[i] + nums2[j]);
            }
        }

        // Sort all sums in descending order
        sort(allSums.begin(), allSums.end(), greater<int>());

        // Return first k elements from the sorted list
        vector<int> result(allSums.begin(), allSums.begin() + k);
        return result;
    }
};

// Driver code
int main() {
    Solution obj;
    vector<int> nums1 = {7, 3};
    vector<int> nums2 = {1, 6};
    int k = 2;
    vector<int> result = obj.maxCombinations(nums1, nums2, k);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}

// Time Complexity: O(n * m + nmlog(nm)) ,We compute all n * m pairwise sums. Sorting takes O(nm log nm). Extracting top k is O(k).
// Space Complexity:O(n * m) , We store all pairwise sums explicitly before sorting and slicing.

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     // Function to find k maximum sum combinations
//     vector<int> maxCombinations(vector<int>& nums1, vector<int>& nums2, int k) {

//         // Sort both arrays in descending order
//         sort(nums1.begin(), nums1.end(), greater<int>());
//         sort(nums2.begin(), nums2.end(), greater<int>());

//         // Max-heap to store pairs with their indices
//         priority_queue<tuple<int, int, int>> maxHeap;

//         // Set to keep track of visited index pairs
//         set<pair<int, int>> visited;

//         // Push the initial maximum pair (nums1[0] + nums2[0])
//         maxHeap.push({nums1[0] + nums2[0], 0, 0});
//         visited.insert({0, 0});

//         // Vector to store the result
//         vector<int> result;

//         // Extract top k elements from the heap
//         while(k-- && !maxHeap.empty()) {

//             // Get the current maximum sum and its indices
//             auto [sum, i, j] = maxHeap.top();
//             maxHeap.pop();

//             // Add this sum to the result
//             result.push_back(sum);

//             // If (i + 1, j) is valid and not visited, add it to the heap
//             if(i + 1 < nums1.size() && !visited.count({i + 1, j})) {
//                 maxHeap.push({nums1[i + 1] + nums2[j], i + 1, j});
//                 visited.insert({i + 1, j});
//             }

//             // If (i, j + 1) is valid and not visited, add it to the heap
//             if(j + 1 < nums2.size() && !visited.count({i, j + 1})) {
//                 maxHeap.push({nums1[i] + nums2[j + 1], i, j + 1});
//                 visited.insert({i, j + 1});
//             }
//         }

//         // Return the final k max combinations
//         return result;
//     }
// };

// // Driver code
// int main() {
//     Solution sol;
//     vector<int> nums1 = {7, 3};
//     vector<int> nums2 = {1, 6};
//     int k = 2;
//     vector<int> result = sol.maxCombinations(nums1, nums2, k);
//     for(int val : result) cout << val << " ";
//     return 0;
// }

// Time Complexity: O(k * log k),The loop runs k times, and in each iteration, we perform heap insertions and deletions, which cost O(log k). In total, this results in O(k log k) time.
// Space Complexity: O(k), The heap and visited set can grow to size k in the worst case.