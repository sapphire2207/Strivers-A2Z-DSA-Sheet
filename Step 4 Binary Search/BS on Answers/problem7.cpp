// Problem 7:-
// You are given a strictly increasing array ‘vec’ and a positive integer ‘k’. Find the ‘kth’ positive integer missing from ‘vec’.

// Example 1:
// Input Format: vec[]={4,7,9,10}, k = 1
// Result: 1
// Explanation: The missing numbers are 1, 2, 3, 5, 6, 8, 11, 12, ……, and so on. Since 'k' is 1, the first missing element is 1.
// Example 2:
// Input Format: vec[]={4,7,9,10}, k = 4
// Result: 5
// Explanation: The missing numbers are 1, 2, 3, 5, 6, 8, 11, 12, ……, and so on. Since 'k' is 4, the fourth missing element is 5.

// Brute Force Method:-
// We will use a loop to traverse the array.
// Inside the loop,
// If vec[i] <= k: we will simply increase the value of k by 1.
// Otherwise, we will break out of the loop.
// Finally, we will return the value of k.
// Note: The main idea is to shift k by 1 step if the current element is smaller or equal to k. And whenever we get a number > k, we can conclude that k is the missing number.
// TC:- O(N)
#include <bits/stdc++.h>
using namespace std;

int missingK(vector < int > vec, int n, int k) {
    for (int i = 0; i < n; i++) {
        if (vec[i] <= k) k++; //shifting k
        else break;
    }
    return k;
}

int main()
{
    vector<int> vec = {4, 7, 9, 10};
    int n = 4, k = 4;
    int ans = missingK(vec, n, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}

// Optimal Approach:-
// We cannot apply binary search on the answer space here as we cannot assure which missing number has the possibility of being the kth missing number. That is why, we will do something different here. We will try to find the closest neighbors (i.e. Present in the array) for the kth missing number by counting the number of missing numbers for each element in the given array.
// Let’s understand it using an example. Assume the given array is {2, 3, 4, 7, 11}. Now, if no numbers were missing the given array would look like {1, 2, 3, 4, 5}. Comparing these 2 arrays, we can conclude the following:
// Up to index 0: Only 1 number i.e. 1 is missing in the given array.
// Up to index 1: Only 1 number i.e. 1 is missing in the given array.
// Up to index 2: Only 1 number i.e. 1 is missing in the given array.
// Up to index 3: 3 numbers i.e. 1, 5, and 6 are missing.
// Up to index 4: 6 numbers i.e. 1, 5, 6, 8, 9, and 10 are missing.
// For a given value of k as 5, we can determine that the answer falls within the range of 7 to 11. Since there are only 3 missing numbers up to index 3, the 5th missing number cannot be before vec[3], which is 7. Therefore, it must be located somewhere to the right of 7. Our actual answer i.e. 9 also supports this theory. So, by following this process we can find the closest neighbors (i.e. Present in the array) for the kth missing number. In our example, the closest neighbors of the 5th missing number are 7 and 11.
// How to calculate the number of missing numbers for any index i?
// From the above example, we can derive a formula to find the number of missing numbers before any array index, i. The formula is
// Number of missing numbers up to index i = vec[i] - (i+1).
// The given array, vec, is currently containing the number vec[i] whereas it should contain (i+1) if no numbers were missing. The difference between the current and the ideal element will give the result.
// After completing the binary search on the indices, the pointer high will point to the closest neighbor(present in the array) that is smaller than the kth missing number. 
// So, in the given array, the preceding neighbor of the kth missing number is vec[high]. 
// Now, we know, up to index ‘high’,
// the number of missing numbers = vec[high] - (high+1).
// But we want to go further and find the kth number. To extend our objective, we aim to find the kth number in the sequence. In order to determine the number of additional missing values required to reach the kth position, we can calculate this as
// more_missing_numbers = k - (vec[high] - (high+1)).
// Now, we will simply add more_missing_numbers to the preceding neighbor i.e. vec[high] to get the kth missing number.
// kth missing number = vec[high] + k - (vec[high] - (high+1))
//         =  vec[high] + k - vec[high] + high + 1
//         = k + high + 1.
// TC:- O(logN)
#include <bits/stdc++.h>
using namespace std;

int missingK(vector < int > vec, int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int missing = vec[mid] - (mid + 1);
        if (missing < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return k + high + 1;
}

int main()
{
    vector<int> vec = {4, 7, 9, 10};
    int n = 4, k = 4;
    int ans = missingK(vec, n, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}