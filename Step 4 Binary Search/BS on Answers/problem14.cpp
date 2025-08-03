// K-th Element of two sorted arrays

// Problem Statement: Given two sorted arrays of size m and n respectively, you are tasked with finding the element that would be at the kth position of the final sorted array.

// Naive Approach (Brute-force)
// The extremely naive approach is to merge the two sorted arrays and then find the K-th element in that merged array.
// How to merge two sorted arrays:
// The word “merge” suggests applying the merge step of the merge sort algorithm . In that step, we essentially perform the same actions as required by this solution. By using two pointers on two given arrays, we fill up the elements into a third array.
#include <bits/stdc++.h>
using namespace std;
            
int kthElement(vector<int> &a, vector<int>& b, int m, int n, int k) {
    vector<int> arr3;
            
    //apply the merge step:
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (a[i] < b[j]) arr3.push_back(a[i++]);
        else arr3.push_back(b[j++]);
    }
            
    //copy the left-out elements:
    while (i < m) arr3.push_back(a[i++]);
    while (j < n) arr3.push_back(b[j++]);
    return arr3[k - 1];
}
            
int main() {
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    cout << "The k-ht element of two sorted array is: " <<
            kthElement(a, b, a.size(), b.size(), 5) << '\n';
}

// Output: The k-th element of two sorted arrays is: 6

// Time Complexity: O(m+n), where m and n are the sizes of the given arrays.
// Reason: We traverse through both arrays linearly.
// Space Complexity: O(m+n), where m and n are the sizes of the given arrays.
// Reason: We are using an extra array of size (m+n) to solve this problem.

// Better Approach (Optimized space)
// To optimize the space used in the previous approach, we can eliminate the third array used to store the final merged result. After closer examination, we realize that we only need the k-th element at index (k-1), rather than the entire merged array, to solve the problem effectively.
// We will stick to the same basic approach, but instead of storing elements in a separate array, we will use a counter called 'cnt' to represent the imaginary third array's index. As we traverse through the arrays, when 'cnt' reaches the index (k-1), we will store that particular element. This way, we can achieve the same goal without using any extra space.

#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int>& b, int m, int n, int k) {
    int ele = -1;
    int cnt = 0; //counter
    //apply the merge step:
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (a[i] < b[j]) {
            if (cnt == k - 1) ele = a[i];
            cnt++;
            i++;
        }
        else {
            if (cnt == k - 1) ele = b[j];
            cnt++;
            j++;
        }
    }

    //copy the left-out elements:
    while (i < m) {
        if (cnt == k - 1) ele = a[i];
        cnt++;
        i++;
    }
    while (j < n) {
        if (cnt == k - 1) ele = b[j];
        cnt++;
        j++;
    }
    return ele;
}

int main() {
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    cout << "The k-ht element of two sorted array is: " <<
            kthElement(a, b, a.size(), b.size(), 5) << '\n';
}
        
// Output: The k-th element of two sorted arrays is: 6

// Time Complexity: O(m+n), where m and n are the sizes of the given arrays.
// Reason: We traverse through both arrays linearly.
// Space Complexity: O(1), as we are not using any extra space to solve this problem.

// ### Optimal Approach (Using Binary Search)
// We are going to use the Binary Search algorithm to optimize the approach.
// The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.
// Note: Please refer to the article Median of 2 sorted arrays to get a detailed overview of this optimal approach.
// The optimal approach will be exactly similar to the one of the problem Median of 2 sorted arrays In that problem, the approach is the following:
// Assume, m = size of arr1[] and n = size of arr2[].
// We know the median creates a partition on the final merged array. So, the array can be divided into two halves that contain almost equal elements. So, the size of the left and right halves is approx. (m+n) / 2.
// We also discussed that for a valid merged array, the left and the right half will be unique.
// So, our approach was to form the unique left half correctly assuming that it contains x elements from arr1[] and ((m+n)/2)-x elements from arr2[]. Now the possible range of the variable x is [0, min(m, n)].
// For all possible values of that range, we checked the configuration of the left half. Now, to validate the left half configuration, we used the condition l1 <= r2 && l2 <=r1. These four variables refer to as follows:
// For example,
// Here, l1 = arr1[1], l2 = arr2[2], r1 = arr1[2], r2 = arr2[3].
// We are going to use the same approach with some minor changes in the values. The changes will be as follows:
// The size of the left half will be k: Here, we don’t need to find the median and instead, we want the k-th element. So, the partition will be after the k-th element. So, the size of the left half will be k instead of (m+n)/2. For example,
// Range of x:
// The maximum possible value of x: We want to build the left subarray of size k. So, the maximum possible value should be k. But if we are considering arr1[] of size n1 and n1 < k, in that case, the maximum possible value will be n1. So, after generalization, the maximum value will be min(k, n1), where n1 = the size of the smaller array. Here n1 = min(m, n).
// The minimum possible value of x: Let’s understand this using an example, given arr1[] size i.e. m = 6, and arr2[] size i.e. n = 5 and k = 7. Now, the lowest value of x(i.e. The no. of elements we should take from arr1[]) should be 2. If we have to build an array of size, 7, and the maximum element we can take from arr2[] is 5, so, we have to take a minimum of 2 elements from arr1[].
// So, the minimum possible value should be k-n2, where n2 = the size of the not-considered array i.e. the bigger array.
// But if k < n2, the k-n2, will be negative. So, to handle this case, we will consider the minimum value as max(0, k-n2), where n2 = the size of the bigger array, and here, n2 = max(m, n).
// The new range of x will be [max(0, k-n2), min(k, n1)], where n1 = the size of the smaller array, and n2 = the size of the bigger array. Here n1 = min(m, n) as we want to optimize the time complexity we will consider the array with a smaller length. And we will apply binary search in this new range.
// Note: The answer will always be max(l1, l2) as the kth element will be the maximum element of the left half.
// The rest of the process will be as similar to the one used in the problem, Median of 2 sorted arrays.

#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int>& b, int m, int n, int k) {
    if (m > n) return kthElement(b, a, n, m, k);

    int left = k; //length of left half

    //apply binary search:
    int low = max(0, k - n), high = min(k, m);
    while (low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        //calculate l1, l2, r1 and r2;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < m) r1 = a[mid1];
        if (mid2 < n) r2 = b[mid2];
        if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }

        //eliminate the halves:
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0; //dummy statement

}

int main() {
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    cout << "The k-th element of two sorted array is: " <<
            kthElement(a, b, a.size(), b.size(), 5) << '\n';
}
        
        
// Output: The k-th element of two sorted arrays is: 6

// Time Complexity: O(log(min(m, n))), where m and n are the sizes of two given arrays.
// Reason: We are applying binary search on the range [max(0, k-n2), min(k, n1)]. The range length <= min(m, n).
// Space Complexity: O(1), as we are not using any extra space to solve this problem.