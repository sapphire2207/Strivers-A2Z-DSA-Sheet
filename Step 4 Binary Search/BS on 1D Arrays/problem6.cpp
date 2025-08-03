// Problem 6:-
// Given a sorted array arr of n integers and a target value k. Write a program to find the indices of the first and the last occurrences of the target value. If the target is not found then return -1 as indices.

// Naive Approach:-
// To do a linear search
// TC:- O(N)
#include<bits/stdc++.h>
using namespace std;

pair<int,int> firstAndLastPosition(vector<int>& arr,int n,int k){
    int first=-1;
    int last=-1;
    for(int i=0;i<=n-1;i++){
        if(arr[i]==k){
            if(first==-1){
                first=i;
            }
            last=i;
        }
    }

    return {first,last};
}

int main(){
    vector<int> arr =  {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 8, k = 8;
    pair<int,int> ans = firstAndLastPosition(arr,n,k);
    cout<<ans.first<<" "<<ans.second<<endl;

    return 0;
}


// Using Lower Bound and Upper Bounds Approach:-
// If we find the lower bound, then it will give you the first occurence, and if you find upper bound, then it is gonna give you a index next to the "last" occurence
// For example, if the given array is {2, 4, 6, 8, 8, 8, 11, 13}, and the target k = 8, the lower bound of 8 will be at index 3(lb), and the upper bound will return index 6(ub). Therefore first=lb=3 && last=ub-1=5
// But to do this we need to take care of the edge cases:-

// Edge Case 1: If the element is not present in the array.
// If the target number is not present in the array, the lower bound will return the index of the nearest greater element. So, in the code, we have to check the following:
// If arr[lb] != k: The element is not present in the array and so, there will be no first or last occurrences. So, we will return -1.

// Edge Case 2: If the element is not present in the array and all the array elements are smaller than the target number.
// In this case, lower bound will return the imaginary index n i.e. the size of the array. We need to handle this case in our code as well.
// If lb == n: No first or last occurrence exists. So, we will return -1.
// TC:- O(2*logN)
#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int lowerBound(vector<int> &arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}


pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int lb = lowerBound(arr, n, k);
    if (lb == n || arr[lb] != k) return { -1, -1};
    int ub = upperBound(arr, n, k);
    return {lb, ub - 1};
}


int main()
{
    vector<int> arr =  {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 8, k = 8;
    pair<int, int> ans = firstAndLastPosition(arr, n, k);
    cout << "The first and last positions are: "
         << ans.first << " " << ans.second << "\n";
    return 0;
}


// Using pure Binary Search:-
// vector<int> arr =  {2, 4, 6, 8, 8, 8, 11, 13};
                      // int n = 8, k = 8;
// Finding the first occurence:
// Case 1 – If arr[mid] == k: This condition means that the index mid may be an answer. So, we will update the ‘first’ variable with mid and search in the left half if there is any smaller index that satisfies the same condition as we want the ‘first’ variable to be as minimum as possible.
// Case 2 – If arr[mid] < k: In this case, mid cannot be our answer and we need to find some bigger element. So, we will eliminate the left half and search in the right half for the answer.
// Case 3: If arr[mid] > k: In this case, mid cannot be our answer and we need to find some smaller element. So, we will eliminate the right half and search in the left half for the answer.

// Finding the last occurence:
// Case 1 – If arr[mid] == k: This condition means that the index mid may be an answer. So, we will update the ‘last’ variable with mid and search in the right half if there is any larger index that satisfies the same condition as we want the ‘last’ variable to be as maximum as possible.
// Case 2 – If arr[mid] < k: In this case, mid cannot be our answer and we need to find some bigger element. So, we will eliminate the left half and search in the right half for the answer.
// Case 3: If arr[mid] > k: In this case, mid cannot be our answer and we need to find some smaller element. So, we will eliminate the right half and search in the left half for the answer.
// TC:- O(2*logN)
#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] == k) {
            first = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else if (arr[mid] < k) {
            low = mid + 1; // look on the right
        }
        else {
            high = mid - 1; // look on the left
        }
    }
    return first;
}

int lastOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int last = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] == k) {
            last = mid;
            //look for larger index on the right
            low = mid + 1;
        }
        else if (arr[mid] < k) {
            low = mid + 1; // look on the right
        }
        else {
            high = mid - 1; // look on the left
        }
    }
    return last;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int first = firstOccurrence(arr, n, k);
    if (first == -1) return { -1, -1};
    int last = lastOccurrence(arr, n, k);
    return {first, last};
}

int main()
{
    vector<int> arr =  {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 8, k = 8;
    pair<int, int> ans = firstAndLastPosition(arr, n, k);
    cout << "The first and last positions are: "
         << ans.first << " " << ans.second << "\n";
    return 0;
}
