//Problem-11:- Finding the maximum consective one's occuring in the given array
//EX:- 1    1   1   0   1   1   0   1   1 --> the Answer will be 3

//Brute Force and Optimised Method:-
//First loop through the entire array, and for continous one's increase your count variable, then if any zero occurs take the maximum of count variable....
// We maintain a variable count that keeps a track of the number of consecutive 1’s while traversing the array. The other variable max_count maintains the maximum number of 1’s, in other words, it maintains the answer.

//TC:- O(N);
//SC:- O(1);
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
    cin>>arr[i];
    }

    int count=0;
    int maximum=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            count++;
            maximum=max(maximum,count);
            // you can also write the max function like this below:
            // if(count > maximum){
            //     maximum = count;
            // }
        }
        else{
            count=0;
        }
    }

    cout<<"The Maximum Consecutive One's occuring in the array is:- "<<maximum;
}