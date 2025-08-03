//INSERTION SORT:-
// The algorithm is that it takes the element from the starting of the array and places in it's correct place
// Ex: 5 4 3 2 1
// TC - O(N^2) - worst and the average case - since while loop will run first time for once, then 2 times,then 3 times and so on....
// But if Ex: 1 2 3 4 5
// Since the while loop is never getting executed
// The while loop will run only once and therefore N times i.e O(N)

#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[],int n){
    //We are going through the entire array i.e from the starting element till the last element so iterate the loop from 0th index to (n-1)th index
    for(int i=0;i<n;i++){
        //Now we should sort the elements till the ith guy by swapping the ith guy to it's correct place by decrementing j till wherever it is possible by adjacent swappings
        //But we take the j till greater than 0 because if j becomes zero the loop will look for the previous index which will not be available while checking whether the element is placed in it's correct place.
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            int temporary=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temporary;
            j--;
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

    insertion_sort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}