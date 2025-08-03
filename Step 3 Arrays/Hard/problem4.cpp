// 4 Sum | Find Quads that add up to a target value

// Problem Statement: Given an array of N integers, your task is to find unique quads that add up to give a target value. In short, you need to return an array of all the unique quadruplets [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.
// Note:
// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// arr[a] + arr[b] + arr[c] + arr[d] == target

// Example 1:
// Input Format: arr[] = [1,0,-1,0,-2,2], target = 0
// Result: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Explanation: We have to find unique quadruplets from the array such that the sum of those elements is equal to the target sum given that is 0. The result obtained is such that the sum of the quadruplets yields 0.

// In the question, it is clearly stated that for each case the picked indices i.e. a, b, c, and d must be distinct. This means [arr[1], arr[1], arr[2], arr[3]] is not valid and also remember [arr[1], arr[0], arr[2], arr[3]] and [arr[0], arr[1], arr[2], arr[3]] will be considered same.

// 1) Brute Force Approach
// Intuition: This approach is pretty straightforward. Here, we will check all possible quadruplets using 4 loops(as we did in the 3-sum problem) and among them, we will consider the ones whose sum is equal to the given target. And before considering them as our answer we need to sort the quadruplets in ascending order.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    set<vector<int>> st;

    //checking all possible quadruplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    // taking bigger data type
                    // to avoid integer overflow:
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main() {
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}


// Output: The quadruplets are: [1 1 3 4 ] [1 2 2 4 ] [1 2 3 3 ]

// Time Complexity: O(N4), where N = size of the array.
// Reason: Here, we are mainly using 4 nested loops. But we not considering the time complexity of sorting as we are just sorting 4 elements every time.
// Space Complexity: O(2 * no. of the quadruplets) as we are using a set data structure and a list to store the quads.

// 2) Better Approach (Using 3 loops and set data structure): 
// In the previous approach, we were using 4 loops but in this, we want to reduce that to 3 loops. We have to somehow manage to calculate nums[l] as we are planning to remove the fourth loop(i.e. l). In order to calculate nums[l], we can derive a formula like the following:
// nums[l] = target - (nums[i]+nums[j]+nums[k])
// So, we will first calculate the triplets nums[i], nums[j], and nums[k] using 3 loops and for the fourth one i.e. nums[l] we will not use another loop and instead we will look up the value target-(nums[i]+nums[j]+nums[k]) in the array. Thus we can remove the fourth loop from the algorithm.
// For implementing the search operation of the fourth element, we will use a similar technique as we used in the case of the 3-sum problem. We will store all the elements between the indices j and k in a HashSet and then we will search for the fourth element in the HashSet.

// Why we are not inserting all the array elements in the HashSet and then searching for the fourth element:
// Let’s understand this intuition using an example. Assume the given array is {1, 2, -1, -2, 2, 0, -1} and the target = 0. Now, we will notice a situation like the following:
// Now, the fourth element should be target-(nums[i]+nums[j]+nums[k]) = 0 - (1-1+0) = 0. Now, if all the array elements are in the HashSet and we search for 0, we will end up taking the 0 at index k again. The quadruplets will be {nums[i], nums[j], nums[k], nums[k]} but this is absolutely incorrect. That is why we need to only consider the elements that are in between the indices j and k.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    set<vector<int>> st;

    //checking all possible quadruplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            set<long long> hashset;
            for (int k = j + 1; k < n; k++) {
                // taking bigger data type
                // to avoid integer overflow:
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long fourth = target - sum;
                if (hashset.find(fourth) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)(fourth)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                // put the kth element into the hashset:
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main() {
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}

// Output: The quadruplets are: [1 1 3 4 ] [1 2 2 4 ] [1 2 3 3 ]

// Time Complexity: O(N3*log(M)), where N = size of the array, M = no. of elements in the set.
// Reason: Here, we are mainly using 3 nested loops, and inside the loops there are some operations on the set data structure which take log(M) time complexity.
// Space Complexity: O(2 * no. of the quadruplets)+O(N)
// Reason: we are using a set data structure and a list to store the quads. This results in the first term. And the second space is taken by the set data structure we are using to store the array elements. At most, the set can contain approximately all the array elements and so the space complexity is O(N).

// 3) Optimal Approach
// In this approach, we intend to get rid of two things i.e. the HashSet we were using for the look-up operation and the set data structure used to store the unique quadruplets.
// Again the solution to this will be similar to the optimal approach of the  3-sum problem. In that approach, we had fixed a pointer i, and the rest 2 pointers were moving. Similarly, here, as we are dealing with quads instead of triplets we will fix 2 pointers i.e. i and j and the rest of the 2 pointers will be moving.
// Now, we need to first understand what the HashSet and the set were doing to make our algorithm work without them. So, the set data structure was basically storing the unique quadruplets in sorted order and the HashSet was used to search for the fourth element.
// To get the quadruplets in sorted order, we will sort the entire array in the first step and to get the unique quads, we will simply skip the duplicate numbers while moving the pointers.

// How to skip duplicate numbers:
// As the entire array is sorted, the duplicate numbers will be in consecutive places. So, while moving a pointer, we will check the current element and the adjacent element. Until they become different, we will move the pointer by 1 place. We will follow this process for all 4 pointers. Thus, we can easily skip the duplicate elements while moving the pointers.
// Now, we can also remove the HashSet as we have two moving pointers i.e. k and l that will find the appropriate value of nums[k] and nums[l]. So, we do not need the HashSet anymore.

// The process will look like the following:
// Among the 4 pointers, 2 will be fixed and 2 will be moving. In each iteration, we will check if the sum i.e. nums[i]+nums[j]+nums[k]+nums[l] is equal to the target. 
// If the sum is greater, then we need lesser elements and so we will decrease the value of l. 
// If the sum is lesser than the target, we need a bigger value and so we will increase the value of k. 
// If the sum is equal to the target, we will simply insert the quad i.e. nums[i], nums[j], nums[k], and nums[l] into our answer and move the pointers k and l skipping the duplicate elements.
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    vector<vector<int>> ans;

    // sort the given array:
    sort(nums.begin(), nums.end());

    //calculating the quadruplets:
    for (int i = 0; i < n; i++) {
        // avoid the duplicates while moving i:
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            // avoid the duplicates while moving j:
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // 2 pointers:
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++; l--;

                    //skip the duplicates:
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
                else if (sum < target) k++;
                else l--;
            }
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}

// Output:The quadruplets are: [1 1 3 4 ] [1 2 2 4 ] [1 2 3 3 ]

// Time Complexity: O(N3), where N = size of the array.
// Reason: Each of the pointers i and j, is running for approximately N times. And both the pointers k and l combined can run for approximately N times including the operation of skipping duplicates. So the total time complexity will be O(N3). 
// Space Complexity: O(no. of quadruplets), This space is only used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).