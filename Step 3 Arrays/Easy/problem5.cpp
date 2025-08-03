//Problem 5:- LEFT ROTATE THE ARRAY BY ONE PLACE
// Ex: 1 2 3 4 5 
// The array after left rotating by one place is: 2 3 4 5 1

//Brute and Optimised Method:-
// Intuition: The rotated array has just a difference that its first element is present at the last index of the array. So if we can just store the element at the first index and then shift all the elements towards the left and at last put the stored element at the last index. We will get th rotated array.
//TC: O(N);
//SC: O(1) - No extra space is used
//But in the algorithm the array space is used for solving the problem
#include<bits/stdc++.h>
using namespace std;

void rotateArray(int arr[],int n){
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    rotateArray(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

//CODE SUBMISSION:-
#include <bits/stdc++.h> 
vector<int> rotateArray(vector<int>& arr, int n) {
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;

    return arr;
}