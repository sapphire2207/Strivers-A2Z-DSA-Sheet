//ARRAYS:-
//If we are declaring an array inside main() we can do it till the size 1e6 & if declared globally 1e7

//PROBLEM 1:-To Find the Largest Element in the given array

//Brute Force Method:-
//First Sort the entire array by quick sort
//Then print the last element of the array
// i.e We can sort the array in ascending order, hence the largest element will be at the last index of the array. 
//TC:- O(NlogN)
//SC:- O(1)

// Optimised Method:-
// We can maintain a largest variable that will update whenever the current value is greater than the value in the largest variable.  
//TC:- O(N)
//SC:- O(1)
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int largest=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }

    cout<<largest<<" ";
}

//CODE SUBMISSION:-
#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {
    int largest=arr[0];

    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    return largest;
}


