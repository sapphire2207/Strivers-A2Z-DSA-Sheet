// 3 Sum : Find triplets that add up to a zero

// Problem Statement: Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.

// Example 1: 
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: Out of all possible unique triplets possible, [-1,-1,2] and [-1,0,1] satisfy the condition of summing up to zero with i!=j!=k

// In the question, it is clearly stated that for each case the picked indices i.e. i, j, and k must be distinct. This means [arr[1], arr[1], arr[2]] is not a valid triplet and also remember [arr[1], arr[0], arr[2]] and [arr[0], arr[1], arr[2]] will be considered the same.

// 1) Brute Force Approach
// This approach is pretty straightforward. Here, we will check all possible triplets using 3 loops and among them, we will consider the ones whose sum is equal to the given target i.e. 0. And before considering them as our answer we need to sort the triplets in ascending order so that we can consider only the unique ones.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &arr) {
    set<vector<int>> st;

    // check all possible triplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    //store the set elements in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


int main() {
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}

// Output: [-1 -1 2 ] [-1 0 1 ]

// Time Complexity: O(N3 * log(no. of unique triplets)), where N = size of the array.
// Reason: Here, we are mainly using 3 nested loops. And inserting triplets into the set takes O(log(no. of unique triplets)) time complexity. But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.
// Space Complexity: O(2 * no. of the unique triplets) as we are using a set data structure and a list to store the triplets.

// 2) Better Approach
// In the previous approach, we utilized 3 loops, but now our goal is to reduce it to 2 loops. To achieve this, we need to find a way to calculate arr[k] since we intend to eliminate the third loop (k loop). To calculate arr[k], we can derive a formula as follows: 
// arr[k] = target - (arr[i]+arr[j]+arr[k]) = 0-(arr[i]+arr[j]+arr[k]) = -(arr[i]+arr[j]+arr[k]) 
// So, we will first calculate arr[i] and arr[j] using 2 loops and for the third one i.e. arr[k] we will not use another loop and instead we will look up the value 0-(arr[i]+arr[j]+arr[k]) in the set data structure. Thus we can remove the third loop from the algorithm.
// For implementing the search operation of the third element,  we will store all the elements between the indices i and j in a HashSet and then we will search for the third element in the HashSet.

// Why we are not inserting all the array elements in the HashSet and then searching for the third element:
// Let’s understand this intuition using an example. Assume the given array is {1, 2, -1, -2, 4, 0, -1} and the target = 0. Now, we will notice a situation like the following:
// Here, arr[i] = -2 and arr[j] = 4.
// Therefore, arr[k] = -(arr[i]+arr[j]) = -(-2+4) = -2
// If all the elements were in the set data structure while searching for -2, we would again pick the element at index 3, that is currently pointed by i.
// Hence, the triplet will be [arr[i], arr[j], arr[i]]. And this is an invalid triplet. That is why we cannot insert all the elements into the set data structure.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &arr) {
    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        set<int> hashset;
        for (int j = i + 1; j < n; j++) {
            //Calculate the 3rd element:
            int third = -(arr[i] + arr[j]);

            //Find the element in the set:
            if (hashset.find(third) != hashset.end()) {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    //store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


int main() {
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}

// Output: [-1 -1 2 ] [-1 0 1 ]

// Time Complexity: O(N2 * log(no. of unique triplets)), where N = size of the array.
// Reason: Here, we are mainly using 3 nested loops. And inserting triplets into the set takes O(log(no. of unique triplets)) time complexity. But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.
// Space Complexity: O(2 * no. of the unique triplets) + O(N) as we are using a set data structure and a list to store the triplets and extra O(N) for storing the array elements in another set.

// 3) Optimal Approach:
// In this approach, we intend to get rid of two things i.e. the HashSet we were using for the look-up operation and the set data structure used to store the unique triplets.
// So, We will first sort the array. Then, we will fix a pointer i, and the rest 2 pointers j and k will be moving. 
// Now, we need to first understand what the HashSet and the set were doing to make our algorithm work without them. So, the set data structure was basically storing the unique triplets in sorted order and the HashSet was used to search for the third element.
// That is why, we will first sort the entire array, and then to get the unique triplets, we will simply skip the duplicate numbers while moving the pointers.

// How to skip duplicate numbers:
// As the entire array is sorted, the duplicate numbers will be in consecutive places. So, while moving a pointer, we will check the current element and the adjacent element. Until they become different, we will move the pointer by 1 place. We will follow this process for all 3 pointers. Thus, we can easily skip the duplicate elements while moving the pointers.
// Now, we can also remove the HashSet as we have two moving pointers i.e. j and k that will find the appropriate value of arr[j] and arr[k]. So, we do not need that HashSet anymore for the look-up operations.

// The process will look like the following:
// Among the 3 pointers, 1 will be fixed and 2 will be moving. In each iteration, we will check if the sum i.e.arr[i]+arr[j]+arr[k] is equal to the target i.e. 0. 
// If the sum is greater, then we need lesser elements and so we will decrease the value of k(i.e. k--). 
// If the sum is lesser than the target, we need a bigger value and so we will increase the value of j (i.e. j++). 
// If the sum is equal to the target, we will simply insert the triplet i.e. arr[i], arr[j], arr[k], into our answer and move the pointers j and k skipping the duplicate elements.
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &arr) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        //remove duplicates:
        if (i != 0 && arr[i] == arr[i - 1]) continue;

        //moving 2 pointers:
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                //skip the duplicates:
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}

// Output: [-1 -1 2 ] [-1 0 1 ]

// Time Complexity: O(NlogN)+O(N2), where N = size of the array.
// Reason: The pointer i, is running for approximately N times. And both the pointers j and k combined can run for approximately N times including the operation of skipping duplicates. So the total time complexity will be O(N2). 
// Space Complexity: O(no. of quadruplets), This space is only used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).