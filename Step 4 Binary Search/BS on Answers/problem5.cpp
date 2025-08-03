// Problem 5:-
// You are given an array of integers ‘arr’ and an integer i.e. a threshold value ‘limit’. Your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the given array by it, the sum of the division’s result is less than or equal to the given threshold value.

// Example 1:
// Input Format: N = 5, arr[] = {1,2,3,4,5}, limit = 8
// Result: 3
// Explanation: We can get a sum of 15(1 + 2 + 3 + 4 + 5) if we choose 1 as a divisor. 
// The sum is 9(1 + 1 + 2 + 2 + 3)  if we choose 2 as a divisor. Upon dividing all the elements of the array by 3, we get 1,1,1,2,2 respectively. Now, their sum is equal to 7 <= 8 i.e. the threshold value. So, 3 is the minimum possible answer.

// Example 2:
// Input Format: N = 4, arr[] = {8,4,2,3}, limit = 10
// Result: 2
// Explanation: If we choose 1, we get 17 as the sum. If we choose 2, we get 9(4+2+1+2) <= 10 as the answer. So, 2 is the answer.

// Point to remember:
// While dividing the array elements with a chosen number, we will always take the ceiling value. And then we will consider their summation. For example, 3 / 2 = 2.

// Observation: 
// Minimum possible divisor: We can easily consider 1 as the minimum divisor as it is the smallest positive integer.
// Maximum possible divisor: If we observe, we can conclude the maximum element in the array i.e. max(arr[]) is the maximum possible divisor. Any number > max(arr[]), will give the exact same result as max(arr[]) does. This divisor will generate the minimum possible result i.e. n(1 for each element), where n = size of the array.
// With these observations, we can surely say that our answer will lie in the range 
// [1, max(arr[])].

// Brute Force Approach:-
// Perform a linear search on the range
// TC:- O(max(arr[])*N), where max(arr[]) = maximum element in the array, N = size of the array.
// Reason: We are using nested loops. The outer loop runs from 1 to max(arr[]) and the inner loop runs for N times.
#include<bits/stdc++.h>
using namespace std;

int check(vector<int>& arr,int n,int threshold){
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        maxi=max(arr[i],maxi);
    }

    for(int d=1;d<=maxi;d++){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=ceil(double(arr[i])/double(d));
        }
        if(sum<=threshold){
            return d; 
        }
    }
    return -1;
}

int main(){
    vector<int> arr={8,4,2,3};
    int n=4,threshold=10;

    int ans = check(arr,n,threshold);
    cout << "The minimum divisor is: " << ans << "\n";

    return 0;
}

// Optimal Approach:-
// Perform binary search on the range of the answers
// Now, we are not given any sorted array on which we can apply binary search. Upon closer observation, we can recognize that our answer space, represented as [1, max(arr[])], is actually sorted. Additionally, we can identify a pattern that allows us to divide this space into two halves: one consisting of potential answers and the other of non-viable options. So, we will apply binary search on the answer space.
// Eliminate the halves based on the summation of division results:
// We will pass the potential divisor, represented by the variable ‘mid’, to the ‘sumByD()‘ function. This function will return the summation result of the division values.
// If result <= threshold: On satisfying this condition, we can conclude that the number ‘mid’ is one of our possible answers. But we want the minimum number. So, we will eliminate the right half and consider the left half(i.e. high = mid-1).
// Otherwise, the value mid is smaller than the number we want. This means the numbers greater than ‘mid’ should be considered and the right half of ‘mid’ consists of such numbers. So, we will eliminate the left half and consider the right half(i.e. low = mid+1).
// Finally, outside the loop, we will return the value of low as the pointer will be pointing to the answer.
// TC:- O(log(max(arr[]))*N), where max(arr[]) = maximum element in the array, N = size of the array.
// Reason: We are applying binary search on our answers that are in the range of [1, max(arr[])]. For every possible divisor ‘mid’, we call the sumByD() function. Inside that function, we are traversing the entire array, which results in O(N).
#include <bits/stdc++.h>
using namespace std;

int sumByD(vector<int> &arr, int div) {
    int n = arr.size(); //size of array
    //Find the summation of division values:
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ceil((double)(arr[i]) / (double)(div));
    }
    return sum;
}

int smallestDivisor(vector<int>& arr, int limit) {
    int n = arr.size();
    if (n > limit) return -1;
    int low = 1, high = *max_element(arr.begin(), arr.end());

    //Apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (sumByD(arr, mid) <= limit) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}

int main(){

    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int ans = smallestDivisor(arr, limit);
    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
}
