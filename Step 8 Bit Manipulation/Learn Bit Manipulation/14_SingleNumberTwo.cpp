// In an array of given Numbers... Every number will be appearing thrice... except one number.... Find that number....

// Brute Force:
//Through Hashing method using map data structure
// The intuition will be the same as the array hashing. The only difference here is we will use the map data structure for hashing instead of using another array for hashing.

//TC:- O(N*logM) + O(M), where M = size of the map i.e. M = (N/3)+1. N = size of the array.
// We are inserting N elements in the map data structure and insertion takes logM time(where M = size of the map). So this results in the first term O(N*logM). The second term is to iterate the map and search the single element. In Java, HashMap generally takes O(1) time complexity for insertion and search. In that case, the time complexity will be O(N) + O(M).

// Note: The time complexity will be changed depending on which map data structure we are using. If we use unordered_map in C++, the time complexity will be O(N) for the best and average case instead of O(N*logM). But in the worst case(which rarely happens), it will be nearly O(N2).

//SC:- O(M) as we are using a map data structure. Here M = size of the map i.e. M = (N/2)+1.
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    unordered_map<long long,int>mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }

    for(auto it:mpp){
        if(it.second==1){
            cout<<"Number "<<it.first<<" is appearing once in the given array"<<endl;
        }
    }
}


// Better Solution:
// Here you first write the given array elements in their binary format.... and traverse all the binary numbers first bit.... then you traverse all the binary numbers second bit....... till 31st bit... and find all the number of set bits.....if it is not a count 3 or multiple of 3 ... then mark it a set bit......
// TC: O(32)*O(N)
// SC: O(1)
int SingleNumberTwo(vector<int> &nums){
    int answer = 0;
    for(int bitIndex = 0; bitIndex <= 31; bitIndex++){
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] & (1 << bitIndex)){
                count++;
            }
        }
        if(count % 3 == 1){
            answer = (answer | (1 << bitIndex));
        }
    }
    return answer;
}

// Better Solution:
// First sort the array of numbers.... and start traversing from the 1st index (consider zero based indexing)... and if you find a prev guy with a different number..... then return that.... if not move three steps ahead....
// TC: O(NlogN) + O(N/3)
// SC: O(1)... we are distorting the given input
int SingleNumberTwo(vector<int> &nums){
    // sort(nums);
    for(int i = 1; i < nums.size(); i = i + 3){
        if(nums[i] != nums[i-1]){
            return nums[i-1];
        }
    }
    return nums[nums.size()-1];
}

// Optimal Solution:
// Here nums[i] will go into ones.... if not in twos
// Here nums[i] will go into twos.... if is in ones......
// Example: [2,2,2,1]
// TC: O(N)
// SC: O(1)
int SingleNumberTwo(vector<int> &nums){
    int ones = 0;
    int twos = 0;
    for(int i = 0; i < nums.size() - 1; i++){
        ones = (ones ^ nums[i]) & ~twos;
        twos = (twos ^ nums[i]) & ~ones;
        // Example: [2,2,2,1]
    }
    return ones;
}