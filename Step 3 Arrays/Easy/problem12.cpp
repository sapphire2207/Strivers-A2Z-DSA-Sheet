//Problem 12:- Find the number that appears once, and the other numbers twice in the given array
//EX:- 1    1   2   3   3    4   4 --> The answer is 2

//Brute Force MEthod:-
//Here we are linear searching for each element in the given array
// For every element present in the array, we will do a linear search and count the occurrence. If for any element, the occurrence is 1, we will return it.

//TC:- O(N*N)
//SC:-O(1)
#include<bits/stdc++.h>
using namespace std;

void appear(int arr[],int n){
    for(int i=0;i<n;i++){
    int count=0;
        for(int j=0;j<n;j++){
            if(arr[j]==arr[i]){
                count++;
            }
        }
        if(count==1){
        cout<<"Number "<<arr[i]<<" is appearing once in the given array"<<endl;
    }
    }
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    appear(arr,n);

    return 0;
}

//Better Solution 1:-
//Through Hashing method using array data structure
// In the previous approach, we were finding the occurrence of an element using linear search. We can optimize this using hashing technique. We can simply hash the elements along with their occurrences in the form of (key, value) pair. Thus, we can reduce the cost of finding the occurrence and hence the time complexity.

//TC:- O(N+N+N)
//SC:- O(Maximum Element) --> creating an extra array
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int maxi=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);
    }

    int hash[maxi+1]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }

    for(int i=1; i<n;i++){
        if(hash[arr[i]]==1){
            cout<<"Number "<<arr[i]<<" is appearing once in the given array"<<endl;
        }
    }

    return 0;
}

//Better Solution 2:-
//Through Hashing method using map data structure
// The intuition will be the same as the array hashing. The only difference here is we will use the map data structure for hashing instead of using another array for hashing.

//TC:- O(N*logM) + O(M), where M = size of the map i.e. M = (N/2)+1. N = size of the array.
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

//Optimal Approach:-
//Using XOR
// Here all the numbers except the single number appear twice and so will form a pair. Now, if we perform XOR of all elements of the array, the XOR of each pair will result in 0 according to the XOR property 1. The result will be = 0 ^ (single number) = single number (according to property 2). So, if we perform the XOR of all the numbers of the array elements, we will be left with a single number.

// TC: O(N), where N = size of the array.
// SC: O(1) as we are not using any extra space.
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int xorr=0;
    for(int i=0;i<n;i++){
        xorr=xorr^arr[i];
    }

    cout<<"Number "<<xorr<<" is appearing once in the given array"<<endl;
}
