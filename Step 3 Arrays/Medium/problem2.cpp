//Problem 2:- Sort an array of 0's 1's and 2's
//You will be given an array containing only 0's 1's and 2's

//Brute Force Method:-
//Using merge Sort algorithm
//TC:- O(N*logN)
//SC:- O(N)

//Better Solution:-
//Here we iterate thorugh all the elements of the array and store the count of each number and replace the array elements with the count we obtained
//TC:- O(2*N)
//SC:- O(1)
#include<bits/stdc++.h>
using namespace std;

void sortArray(vector<int>& arr,int n){
    int count0=0;
    int count1=0;
    int count2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) count0++;
        else if(arr[i]==1) count1++;
        else count2++;
    }

    for(int i=0;i<count0;i++){
        arr[i]=0;
    }
    for(int i=count0;i<count0+count1;i++){
        arr[i]=1;
    }
    for(int i=count0+count1;i<n;i++){
        arr[i]=2;
    }

    for(auto it:arr){
        cout<<it<<" ";
    }
}

int main(){
    int n=6;
    vector<int> arr={0,2,1,2,0,1};

    sortArray(arr,n);

    return 0;
}


//OPTIMAL METHOD:-
//DUTCH NATIONAL FLAG ALGORITHM:-
//We use the three pointer approach. Intially the low and the mid indexes will be at zero, and the high index will be at n-1.
//First always visualize the diagram while solving the problem
// (0 - low-1) - sorted part with zeroes
// (low - mid-1) - sorted part with ones
// (high+1 - n-1) - sorted part with twos
//So from (mid - high) - there will be an unsorted array containing 0,1,2
//Based on the element that occur in the unsorted array we move the indexes of low,mid and high
// i.e if the element that occurs is 0, then it means that to satisfy the above diagram swap the position of low and mid and move both the pointers
// if the element that occurs is 1, then to satisfy the above diagram just move the mid pointer 
// if the element that occurs is 2, then to satisfy the above diagram swap the mid and high indexes and decrement the high pointer
//TC:- O(N) - beacuse at every iteration we are sorting atleast one element, i.e at every iteration, every element is going ointo it's correct place
//SC:- O(1)
#include<bits/stdc++.h>
using namespace std;

void sortArray(vector<int>& arr,int n){
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }

    for(auto it:arr){
        cout<<it<<" ";
    }
    
}

int main(){
    int n=11;
    vector<int> arr={0,1,1,0,1,2,1,2,0,0,0};

    sortArray(arr,n);

    return 0;
}