// Problem 9:- Leaders in an array
// Given array: {10,22,12,3,0,6}. Find the elements which are the leaders of the array, i.e for example, 22, after the element 22 there is no other elements greater than that, so it is a leader. therfore leaders are {22,12,6}, print them in a sorted manner

// Brute Force Method:-
// Here we do linear search for each element whether it's the leader element or not
// TC:- O(N^2)
// SC:- O(N)
#include<bits/stdc++.h>
using namespace std;

void leader(vector<int>& arr,int n){
    vector<int> ans;
    for(int i=0;i<n;i++){
        bool isLeader=true;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                isLeader=false;
                break;
            }
        }
        if(leader){
            ans.push_back(arr[i]);
        }
    }
    
    for(auto it:ans){
        cout<<it<<" ";
    }
}

int main(){
    int n=6;
    vector<int> arr={10,22,12,3,0,6};

    leader(arr,n);

    return 0;
}

// Optimal Method:-
// {10,22,12,3,0,6} 
// Here we see whether the array element is greater than the maximum element on the right. Here we iterate from the last. Here at first 6 is max, then if i is at 1 nothing happens, if i is at 3 nothing happens, if i is at 12, it's greater than maximum i.e 6 so it's added into array.......
// TC:- O(N) + O(NlogN)
// SC:- O(N)
#include<bits/stdc++.h>
using namespace std;

void find(vector<int>& arr, int n){
    vector<int> ans;
    int maximum=INT_MIN;
    for(int i=n-1;i>=0;i++){
        if(arr[i]>maximum){
            ans.push_back(arr[i]);
        }
        maximum=max(maximum,arr[i]);
    }

    sort(ans.begin(),ans.end());

    for(auto it:ans){
        cout<<it<<" ";
    }
}

int main(){
    int n=6;
    vector<int> arr={10,22,12,3,0,6};

    find(arr,n);

    return 0;
}