//FINDING THE LONGEST SUB ARRAY SUM
//Input Format: N = 5, k = 10, array[] = {2,3,5,1,9}
//Result: 3
//Explanation: The longest subarray with sum 10 is {2, 3, 5}. And its length is 3.

//Brute Force Method:-
//Generate all the subarrays and find the sum of each and every subarray, and return the longest subarray's length
//TC:- O(N^3)
//SC:- O(1)
#include<bits/stdc++.h>
using namespace std;

void subArray(int arr[],int k,int n){
    int length=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int K=i;K<=j;K++){
                sum+=arr[K];
            }
            if(sum==k){
                length=max(length,j-i+1);
            }
        }
    }
    cout<<"The longest subarray's array's length is:"<<length<<endl;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int k;
    cin>>k;

    subArray(arr,k,n);

    return 0;
}

//Brute Force 2:-
//Instead of running the third loop, add the elements to the sum variable whenever you move the jth index
//TC:- O(N^2)
//SC:- O(1)
#include<bits/stdc++.h>
using namespace std;

void subArray(int arr[],int k,int n){
    int length=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==k){
                length=max(length,j-i+1);
            }
        }
    }

    cout<<"The longest subarray's array's length is:"<<length<<endl;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int k;
    cin>>k;

    subArray(arr,k,n);

    return 0;
}


//Better Solution:-
// If there exists a sub-array with sum 'k' as (.) element as the last element
// Using the hashing approach, at a particular index of the array, assume the sum 'x', and there may exist the actual sum we want i.e 'k' till that particluar index, and we can apply reverse mathematics and store the 'x-k'th which is the left over element's sum, to make the calculation faster
//The array may contain positives and zeroes
//TC:- if using an ordered map - O(N*logN)
//     if using an unordered map - O(N*1) and in worst case - O(N*N)
//SC:- O(N) in worst case where each element store a seperate sum in the hash map
//This better solution is the Optimal approach for finding the longest subarray containing positives,negatives and zeores
#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        long long rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

int main(){
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}

//Optimal Method:-
//Here we are using the two pointer approach, keep a pointer at the start, then keep on moving the second pointer and add that pointer's index to the sum,if it equals to the sum find the length by subtracting the right and the left indexes and add 1 to it, when the sum exceeds the given 'k' value subtract the element at the left pointer and move it forward.
//TC:- O(2*N) - the inner while loop only runs for sometimes so it just adds the outer while loop's iteration
//SC:- O(1)
#include<bits/stdc++.h>
using namespace std;

void subArray(int arr[],int n,int k){
    int left=0;
    int right=0;
    long long sum=arr[0];
    int maxLen=0;
    while(right<n){ 
        // Can also be done using sliding window approach.... => it will take O(N) instead of O(2N) if we use if instead of while loop...
        while(left<=right && sum>k){
            sum-=arr[left];
            left++;
        }
        if(sum==k){
            maxLen=max(maxLen,right-left+1);
        }
        right++;
        sum+=arr[right];
    }

    cout<< maxLen;
}

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int k;
    cin>>k;

    subArray(arr,n,k);

    return 0;
}


