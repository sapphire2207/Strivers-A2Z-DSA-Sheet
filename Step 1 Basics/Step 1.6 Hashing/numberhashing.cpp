// Given an array of integers: [1, 2, 1, 3, 2] and we are given some queries: [1, 3, 4, 2, 10]. For each query, we need to find out how many times the number appears in the array. For example, if the query is 1 our answer would be 2, and if the query is 4 the answer will be 0. 

// METHOD 1:-BRUTE FORCE METHOD
// The Time complexity of the function will be O(N) ignoring the other constant operations. 
// Now, for each query, we are calling this function. So, if the query contains 5 numbers and we call the function 5 times, the total time complexity will be O(5*N). If the number of queries is Q, the time complexity will be O(Q*N).

// if the length of the query becomes large like 10^5 and the array size also becomes large like 10^5, the time complexity will be O(10^10).We know from our previous knowledge that 10^8 operations take 1 second to get executed. So, 10^10 operations will take around 100 seconds(10^10/10^8). We cannot say a code is good if it takes 100 seconds to get executed.
#include<bits/stdc++.h>
using namespace std;

int queryCount(int arr[],int q,int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==q){
            count+=1;
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int q;
    cin>>q;

    int appear=queryCount(arr,q,n);
    cout<<appear;
}

//METHOD 2:- Optimized approach using Hashing
//The definition of HASHING in a naive way, it is nothing but the combination of the steps, pre-storing, and fetching.
//TC - O(N) + O(N) + O(q)
//SC - O(13) Only for this case
//Inside main you can declare an array of integers size less than or equal to 10^6(1e6)
//If declaring outside it can be done till 10^7(1e7).
// Therefore,We may encounter a problem where the maximum array element may be very large like 10^9. In that case, theoretically, we should declare an array of size 10^9+1. But we cannot do so.
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //precompute:
    int hash[13] = {0};
    for (int i = 0; i < n; i++) {
        hash[arr[i]] += 1;
    }

    int q;
    cin >> q;
    while (q--) {
        int number;
        cin >> number;
        // fetching:
        cout << hash[number] << endl;
    }
    return 0;
}

//METHOD 3:- Space Optimised Method using map data structure

// TC:-
// The total time complexity will be O(N * time taken by map data structure).
// Storing(i.e. insertion) and fetching(i.e. retrieval) in a C++ map, both take always O(logN) time complexity, where N = the size of the map. 
// map takes O(logN) - best,average,worst => O(N * logN)
// unordered map takes O(1) - best and average => O(N * 1), worst is O(N) => O(N * N)
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //precompute:
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }

    // iterate over the map:
    /* for(auto it : mp){
            cout << it.first << "->" << it.second << endl;
        }
    */

    int q;
    cin >> q;
    while (q--) {
        int number;
        cin >> number;
        // fetch:
        cout << mp[number] << endl;
    }
    return 0;
}

// Note:
// Time complexity of map data structure:
// The total time complexity will be O(N * time taken by map data structure).

// Storing(i.e. insertion) and fetching(i.e. retrieval) in a C++ map, both take always O(logN) time complexity, where N = the size of the map. 

// But the unordered_map in C++ and HashMap in Java, both take O(1) time complexity to perform storing(i.e. insertion) and fetching(i.e. retrieval). Now, it is valid for the best case and the average case. 

// But in the worst case, this time complexity will be O(N) for unordered_map. Now, the worst case occurs very very rarely. It almost never happens and most of the time, we will be using unordered_map. 