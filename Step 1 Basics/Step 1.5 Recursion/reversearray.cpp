//REVERSING THE GIVEN ARRAY

// METHOD 1:- Using an Extra array
// Approach: Declare an array,ans[] of the same size as the input array. Iterate from the back of the input array while storing the elements in ans[]  in opposite direction.

//TC - O(N) n is the size of the array
//SC - O(N) since extra space is used
#include <iostream>
using namespace std;

void printArray(int ans[], int n) {
  cout << "The reversed array is:- " << endl;
   for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
   }
}

void reverseArray(int arr[], int n) {
   int ans[n];
   for (int i = n - 1; i >= 0; i--) {
      ans[n - i - 1] = arr[i];
   }
   printArray(ans, n);
}
int main() {
   int n = 5;
   int arr[] = {5,4,3,2,1};
   reverseArray(arr, n);
   return 0;
}


//METHOD 2:-Two pointer approach
// Approach: 
// Unlike the previous method we use the same array to obtain the result. Follow the steps below:
// Step 1 :Keep a pointer p1  at the first index and another p2 at the last index of the array. 
// Step 2 :Swap the elements pointed by p1 and p2, Post swapping increment p1 and decrement p2.
// Step 3 :This process is repeated for only the first n/2 elements where n is the length of array.

//TC - O(N) n is the size of the array
//SC - O(1) since no extra space is used
#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
   cout << "The reversed array is:- " << endl;
   for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
}

void reverseArray(int arr[], int n) {
   int p1 = 0, p2 = n - 1;
   while (p1<p2) {
      swap(arr[p1], arr[p2]);
    //   int temp=arr[p1];
    //   arr[p1]=arr[p2];
    //   arr[p2]=temp;
      p1++; p2--;
   }
   printArray(arr, n);
}
int main() {
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   reverseArray(arr, n);
   return 0;
}

//METHOD 3.1:-Using Recusrion by passing of two variables
// Approach: The recursive method has an approach almost similar to the iterative one. The approach has been broken down into some steps for simplicity. Follow the below steps:
// Step 1 : Create a function that takes an array, start index, and end index of the array as parameters.
// Step 2 : Swap the elements present  at the start and end index, 
// Step 3 : The portion of the array left to be reversed is arr[start+1,end-1]. Make a recursive call to reverse the rest of the array. While calling recursion pass start +1  and ends - 1 as parameters for the shrunk array. Repeat step 2.
// Step 4 : Continue recursion as long as the ‘start < end’ condition is satisfied. This is the base case for our recursion.

//TC - O(N) 
//SC - O(1)
#include<bits/stdc++.h>
using namespace std;

void reverseArray(int start,int arr[],int end){
    if(start>=end) return;
    swap(arr[start],arr[end]);
    reverseArray(start+1,arr,end-1);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    reverseArray(0,arr,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

//METHOD 3.2:-Using Recursion by passing of single variable
//TC - O(N) 
//SC - O(1)
#include<bits/stdc++.h>
using namespace std;

void reverseArray(int i,int arr[],int n){
    if(i>=n/2) return;
    swap(arr[i],arr[n-i-1]);
    reverseArray(i+1,arr,n);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    reverseArray(0,arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

//METHOD 4:- Using reverse(arr, arr + n); It's a library function
// Approach: C++ and Java have inbuilt functions to reverse an array.
// The std::reverse function in C++ is predefined in a header file algorithm.
// Syntax: array_name.reverse(BidirectionalIterator first, BidirectionalIterator last)
// Bidirectional iterators first and last indicate the starting and ending positions in the array. Elements that lie in this range are reversed. Note that this range includes the first but excludes the last element.

//TC - O(N) 
//SC - O(1)
#include <iostream>
#include<algorithm>

using namespace std;
//Function to print array
void printArray(int arr[], int n) {
   cout << "The reversed array is:- " << endl;
   for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
}
//Reverse array using library function
void reverseArray(int arr[], int n) {
   //Reversing elements from index 0 to n-1 
   reverse(arr, arr + n);
}
int main() {
   int n = 5;
   int arr[] = { 5, 4, 3, 2, 1 };
   reverseArray(arr, n);
   printArray(arr, n);
   return 0;
}



//CODE SUBMISSION:-
// void reversing(int i,vector<int>&nums,int n){
//     if(i>=n/2) return;
//     swap(nums[i],nums[n-i-1]);
//     reversing(i+1,nums,n);
// }

// vector<int> reverseArray(int n, vector<int> &nums){
  
//     reversing(0,nums,n);

//     return nums;
// }