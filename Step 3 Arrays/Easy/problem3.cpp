//Problem 3:- To Check whether the given array is sorted

//Brute and Optimised method:-
// If the previous element is smaller than or equal to the current element then. Then we can say that the two elements are sorted. If the condition is true for the entire array then the array is sorted. We will check every element with its previous element if the previous element is smaller than or equal to the current element then we will move to the next index.
//TC:- O(N)
//SC:- O(1)
#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[],int n){
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    bool ans=isSorted(arr,n);

    cout<<ans;
}

//CODE SUBMISSION:-
int isSorted(int n, vector<int> a) {
    for(int i=1;i<n;i++){
        if(a[i-1]<=a[i]){

        }
        else{
            return false;
        }
    }
    return true;
}