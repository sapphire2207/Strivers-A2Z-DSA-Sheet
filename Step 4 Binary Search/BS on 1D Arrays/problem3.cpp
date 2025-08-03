// Problem 3:- Implement Upper Bound

// Upper Bound: it is the smallest index such that arr[index]>x, where "x" is the target
// Ex: arr={1,2,3,3,5,8,8,10,10,11} and if the target is "10" then the answer is 9
                                     // if the target is "2" then the answer is 2

// Here we maintain the same approach as binary search, in addition to that, here we just only check two cases
// if arr[mid]>x, then it means that this "mid" element may one of the upper bounds, since we need the smallest, so we trim down the search space to check whether there is a better upper bound, by moving the search space to the left
// then the other case will be not satisfying the condition arr[mid]>x --> eg: arr[4]>9 ==> 5>9, it means that there is no use in searching in the left side of the array,so we move to the right search space
// TC: O(logN) --> logN base 2
#include<bits/stdc++.h>
using namespace std;

int ub(vector<int>& arr,int n,int target){
    int low=0;
    int high=n-1;
    int ans=n;

    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>target){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }

    return ans;
}

int main(){
    int n=10;
    vector<int> arr = {1,2,3,3,5,8,8,10,10,11};
    int target=9;

    int ans=ub(arr,n,target);

    if(ans==-1){
        cout<<n;
    }else {
        cout<<ans;
    }
    return 0;
}

// Another method:-
// Using STL in c++, we can find upperbound by:
// int ub= upper_bound(arr.begin(),arr.end(),n)-arr.begin();