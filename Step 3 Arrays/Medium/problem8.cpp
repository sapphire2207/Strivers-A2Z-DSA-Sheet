// Problem 8:-
// You will be given an array for ex: {3,1,2} ==> You should return the next permutation, i.e generally the permutations are in the form of dictionary i.e {1,2,3}, {1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1} 
// In the particular question, you should return {3,2,1}.

// Brute Force Method:-
// 1) Find the all possible permutations of elements and store them
// 2) search input from all possible permutations
// 3) print the next permutation present right after it
// Refer this question when you do recursion
// TC:- O(N!*N) ==> N! will be the number of permuations and N will be the size of each permuations, so if array size is 15 then the iterations will be 10^12, so we don't prefer Brute Force

// Better Method:-
// In STL we have a function called next_permutation(arr.begin(),arr.end()); which will automatically give you 
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int arr[] = {1,3,2};
    
    next_permutation(arr,arr+3);//using in-built function of C++
    
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
    
    return 0;
}


// Optimal Method:-
// Ex:- {2,1,5,4,3,0,0}
// Here if we take all the 7 and 6 elements into consideration you will get only that array
// If you take 5 elements into consideration, you may get a permutation but it will not be the next
// If you take 4 elements, you may get a permutation but not the next one which is required
// If you take 3 and 2 elements, you may get a permutation but not the next permutation
// But if you take 1 elemnt, here you can get the next permutation. This process got repeated because we always needed a number which is greater than the elements taken into consideration, but we never found them.
// 1) Search for a longer prefix match, so that you get a break point where you get the required index, so if you get thaat index, you can find the smallest maximum element to replace it from the remaining elements: a[i]<a[i+1]
// The breakpoint may in the worst case may occur at (n-2)th index
// 2) if > 1, but the smallest one, swap it
// 3) place them in a sorted order

// TC:- O(3*N)
// SC:- O(N) / O(1)
#include<bits/stdc++.h>
using namespace std;

void permutation(vector<int>& arr,int n){
    int index=-1;
    for(int i=n-2;i>=0;i++){
        if(arr[i]<arr[i+1]){
            index=i;
            break;
        }
    }

    if(index==-1){
        reverse(arr.begin(),arr.end());
    }

    for(int i=n-1;i>index;i++){
        if(arr[i]>arr[index]){
            swap(arr[i],arr[index]);
            break;
        }
    }

    reverse(arr.begin()+index+1,arr.end());

    for(auto it:arr){
        cout<<it<<" ";
    }
}

int main(){
    int n=7;
    vector<int> arr={2,1,5,4,3,0,0};

    permutation(arr,n);

    return 0;
}

