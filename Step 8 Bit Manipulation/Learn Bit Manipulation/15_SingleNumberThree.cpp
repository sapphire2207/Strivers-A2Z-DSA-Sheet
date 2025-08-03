// Two numbers with odd occurrences
// Given an unsorted array, Arr[] of size N and that contains even number of occurrences for all numbers except two numbers. Find the two numbers in decreasing order which has odd occurrences.z

// Brute Force Method: Hashing... Storing the frequencies
// TC:- O(N*logM) + O(M), where M = size of the map i.e. M = (N/2)+1. N = size of the array.
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // O(NlogM)
    unordered_map<long long,int>mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }

    vector<int> ans;

    // O(M)
    for(auto it:mpp){
        if(it.second==1){
            ans.push_back(it.first);
        }
    }

    for(auto it: ans){
        cout << it << " " << endl;
    }
}

// Optimal:
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, nums[n];
    long xorr = 0;
    for(int i = 0; i < n - 1; i++){
        xorr = xorr ^ nums[i];
    }

    int rightMost = (xorr & xorr - 1) & xorr;
    int b1 = 0, b2 = 0;
    for(int i = 0; i < n - 1 ; i++){
        if(nums[i] & rightMost){
            b1 = b1 ^ nums[i];
        }
        else{
            b2 = b2 ^ nums[i];
        }
    }
}