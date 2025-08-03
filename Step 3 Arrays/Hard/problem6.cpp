// Count the number of subarrays with given xor K

// Problem Statement: Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to k.

// Example 1:
// Input Format: A = [4, 2, 2, 6, 4] , k = 6
// Result: 4
// // Explanation: The subarrays having XOR of their elements as 6 are  [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]

// Brute Force Approach
// Here, in this approach, we are going to generate all possible subarrays to solve this problem.
// How to generate all possible subarrays?
// We will select all possible starting indices(say i) and all possible ending indices(say j) to generate all possible subarrays. The possible starting indices i.e. i can vary from index 0 to index n-1(i.e. The last index). For every index i, the possible ending index j can vary from i to n-1.
// We will check the XOR of every possible subarray and count how many of them are equal to k. To get every possible subarray sum, we will be using three nested loops. The first two loops(say i and j) will iterate over every possible starting index and ending index of a subarray. Basically, in each iteration, the subarray range will be from index i to index j. Using another loop we will get the XOR of the elements of the subarray [i…..j]. Among all values of the XOR calculated, we will only consider those that are equal to k.
// Note: We are selecting every possible subarray using two nested loops and for each of the subarrays, we are calculating the XOR of all its elements using another loop.
#include <bits/stdc++.h>
using namespace std;

int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int cnt = 0;

    // Step 1: Generating subarrays:
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {

            //step 2:calculate XOR of all
            // elements:
            int xorr = 0;
            for (int K = i; K <= j; K++) {
                xorr = xorr ^ a[K];
            }

            // step 3:check XOR and count:
            if (xorr == k) cnt++;
        }
    }
    return cnt;
}

int main() {
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}

// Output: The number of subarrays with XOR k is: 4

// Time Complexity: O(N3) approx., where N = size of the array.
// Reason: We are using three nested loops, each running approximately N times.
// Space Complexity: O(1) as we are not using any extra space.

// Better Approach
// Intuition: If we carefully observe, we can notice that to get the XOR of the current subarray we just need to XOR the current element(i.e. arr[j]) to the XOR of the previous subarray i.e. arr[i….j-1].
// Assume previous subarray = arr[i……j-1]
// current subarray = arr[i…..j]
// XOR of arr[i….j] = (XOR of arr[i….j-1]) ^ arr[j]
// This is how we can remove the third loop and while moving j pointer, we can calculate the XOR.
#include <bits/stdc++.h>
using namespace std;

int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int cnt = 0;

    // Step 1: Generating subarrays:
    for (int i = 0; i < n; i++) {
        int xorr = 0;
        for (int j = i; j < n; j++) {

            //step 2:calculate XOR of all
            // elements:
            xorr = xorr ^ a[j];

            // step 3:check XOR and count:
            if (xorr == k) cnt++;
        }
    }
    return cnt;
}

int main() {
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}

// Output: The number of subarrays with XOR k is: 4

// Time Complexity: O(N2), where N = size of the array.
// Reason: We are using two nested loops here. As each of them is running for N times, the time complexity will be approximately O(N2).
// Space Complexity: O(1) as we are not using any extra space.

// Optimal Approach
// In this approach, we are going to use the concept of the prefix XOR to solve this problem. Here, the prefix XOR of a subarray ending at index i, simply means the XOR of all the elements of that subarray.
// Observation: Assume, the prefix XOR of a subarray ending at index i is xr. In that subarray, we will search for another subarray ending at index i, whose XOR is equal to k. Here, we need to observe that if there exists another subarray ending at index i, with XOR k, then the prefix XOR of the rest of the subarray will be xr^k. The below image will clarify the concept:
// Now, for a subarray ending at index i with the prefix XOR xr, if we remove the part with the prefix XOR xr^k, we will be left with the part whose XOR is equal to k. And that is what we want.
// Now, there may exist multiple subarrays with the prefix XOR xr^k. So, the number of subarrays with XOR k that we can generate from the entire subarray ending at index i, is exactly equal to the number of subarrays with the prefix XOR xr^k, present in that subarray.
// So, for a subarray ending at index i, instead of counting the subarrays with XOR k, we can count the subarrays with the prefix XOR xr^k present in it.
// That is why, instead of searching the subarrays with XOR k, we will keep the occurrence of the prefix XOR of the subarrays using a map data structure. 
// In the map, we will store every prefix XOR calculated, with its occurrence in a <key, value> pair. Now, at index i, we just need to check the map data structure to get the number of times that the subarrays with the prefix XOR xr^k occur. Then we will simply add that number to our count.
// We will apply the above process for all possible indices of the given array. The possible values of the index i can be from 0 to n-1(where n = size of the array).

// Question: Why do we need to set the value of 0 beforehand?
// Let’s understand this using an example. Assume the given array is [3, 3, 1, 1, 1] and k is 3. Now, for index 0, we get the total prefix XOR as 3, and k is also 3. So, the prefix XOR xr^k will be = 3^3 = 0. Now, if the value is not previously set for the key 0 in the map, we will get the default value 0 and we will add 0 to our answer. This will mean that we have not found any subarray with XOR 3 till now. But this should not be the case as index 0 itself is a subarray with XOR k i.e. 3.
// So, in order to avoid this situation we need to set the value of 0 as 1 on the map beforehand.
#include <bits/stdc++.h>
using namespace std;

int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int xr = 0;
    map<int, int> mpp; //declaring the map.
    mpp[xr]++; //setting the value of 0.
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        // prefix XOR till index i:
        xr = xr ^ a[i];

        //By formula: x = xr^k:
        int x = xr ^ k;

        // add the occurrence of xr^k
        // to the count:
        cnt += mpp[x];

        // Insert the prefix xor till index i
        // into the map:
        mpp[xr]++;
    }
    return cnt;
}

int main() {
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}

// Output: The number of subarrays with XOR k is: 4

// Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
// Reason: For example, if we are using an unordered_map data structure in C++ the time complexity will be O(N) but if we are using a map data structure, the time complexity will be O(N*logN). The least complexity will be O(N) as we are using a loop to traverse the array. Point to remember for unordered_map in the worst case, the searching time increases to O(N), and hence the overall time complexity increases to O(N2). 
// Space Complexity: O(N) as we are using a map data structure.