// Problem: Check if there exists a subsequence with sum K
// Approach: Recursion (Pick/Not Pick) with base conditions

/*

Core Idea:
We want to check if there exists at least one subsequence in the array
whose sum is exactly equal to K.
This is a classic "pick or not pick" recursive approach.

We try each element:
- Include it in our sum (pick)
- Exclude it from our sum (not pick)
If at any point we reach the end of the array and our current sum matches K,
we return true (1). Otherwise, we keep searching.

*/

/*

Explanation:
We are calling the recursive function "f" starting from index 0 and initial sum 0.
For every element in the array, we have 2 options:
1. Include it in the sum => f(index+1, sum + arr[index], ...)
2. Exclude it from the sum => f(index+1, sum, ...)

Eventually, when we reach the end of the array (index == arr.size()),
we check if the sum equals K.
If yes, we return true.

Because we're using OR (||), the moment we find one valid path that returns true,
it bubbles up to the main function and prints the success message.

Dry Run on arr = {1, 2, 1}, K = 2:
- Subsequence [1, 1] => sum = 2 => valid ✅
- All other subsequences either sum to less or more than 2 ❌
So answer is: Yes

*/

#include <iostream>
#include <vector>
using namespace std;

bool f(int index, int sum, const vector<int>& arr, int K) {
    // Base Case
    if (index == arr.size()) {
        return sum == K; // return true if sum equals K, else false
    }

    // Pick the current element
    bool pick = f(index + 1, sum + arr[index], arr, K);

    // Not pick the current element
    bool notPick = f(index + 1, sum, arr, K);

    // If any of the two return true, that means there exists a valid subsequence
    return pick || notPick;
}

int main() {
    vector<int> arr = {1, 2, 1};
    int K = 2;

    if (f(0, 0, arr, K)) {
        cout << "Yes, a subsequence with sum " << K << " exists." << endl;
    } else {
        cout << "No, there is no subsequence with sum " << K << "." << endl;
    }

    return 0;
}

// Time Complexity: O(2^n), where n is the number of elements in the array