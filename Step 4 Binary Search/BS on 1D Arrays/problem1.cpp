// Problem 1:- Binary Search
// You are given a sorted array of integers and a target, your task is to search for the target in the given array. Assume the given array does not contain any duplicate numbers.
// Let’s say the given array is = {3, 4, 6, 7, 9, 12, 16, 17} and target = 6.

// Binary search is only applicable in a sorted search space. The sorted search space does not necessarily have to be a sorted array. It can be anything but the search space must be sorted.
// In binary search, we generally divide the search space into two equal halves and then try to locate which half contains the target. According to that, we shrink the search space size.

// Iterative Approach:-
// Here we have 3 pointers, "low" at the first index, "high" at the last index, and "mid" at (low+high/2) index, now our aim is to find the the target "k"
// So using the dictionary approach, if the target "k" is less than the "mid", it means that the target "k" is present in the left part of the array, i.e we can reduce the search space by moving the "high" to "mid-1"
// And if the target "k" is more than the "mid", it means that the target "k" is present in the right paryt of the array, i.e we can reduce the search space by moving the "low" to "mid+1"
// And if the target "k" is equal to "mid" then return that index
// This above two steps will be done until you reach the third step, if you were not able to find the index then you will be with the condition "low>high", because even after reducing the search space there is no index with that particular target "k"
// TC:- O(logN) --> N is the size of the array, bcz we are dividing the search space into two halves everytime
#include<bits/stdc++.h>
using namespace std;

int bs(vector<int>& arr,int n,int target){
    int low=0;
    int high=n-1;
    

    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(target<arr[mid]){
            high=mid-1;
        }else {
            low=mid+1;
        }
    }
}

int main(){
    int n=8;
    vector<int> arr={3, 4, 6, 7, 9, 12, 16, 17};
    int target=6;

    int ans=bs(arr,n,target);

    if(ans==-1){
        cout<<"No element found";
    }else{
        cout<<"The required element is present at "<<ans<<endl;
    }
    return 0;
}

// Recursive Approach:-
// We are doing the same thing as above, instead of everytime reducing the same search space by making changes to the variables, here we are using recursion to automatically do the things, so the base case is low>high
// TC:- O(logN) --> N is the size of the array, bcz we are dividing the search space into two halves everytime
#include<bits/stdc++.h>
using namespace std;

int bs(vector<int>& arr,int n,int target,int low,int high){

    if(low>high){
        return -1;
    }
    
    int mid=(low+high)/2;
    if(arr[mid]==target){
        return mid;
    }
    else if(target<arr[mid]){
        return bs(arr,n,target,low,mid-1);
    }
    else {
        return bs(arr,n,target,mid+1,high);
    }
}

int search(vector<int>& arr,int n,int target){
    return bs(arr,n,target,0,n-1);
}

int main(){
    int n=8;
    vector<int> arr={3, 4, 6, 7, 9, 12, 16, 17};
    int target=6;

    int ans=search(arr,n,target);

    if(ans==-1){
        cout<<"No element found";
    }
    return 0;
}

// Overflow case: if the size of the array is INT_MAX, then "low" will be at 0, "high" will be at INT_MAX, and if the target is "high" element, then while calulating "mid" it exceeds the value, i.e it can't be calculated, so to solve this, change the datatypes to "long long" or else calculate "mid" using: low + (high - low)/2