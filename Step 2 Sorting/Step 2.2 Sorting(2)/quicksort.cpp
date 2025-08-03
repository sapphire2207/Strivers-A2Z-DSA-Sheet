//QUICK SORT

//The Algorithm is divide and conquer
//First Place a pivot in it's correct place by using the algorithm.
//Then place the smaller elements on the left and the the larger elements on the right
//Using recursion repeat the above two steps for the left part and the right part

//TC:- O(NlogN)
//SC:- O(1)
#include<bits/stdc++.h>
using namespace std;

int index(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;

    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }

        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void quickSort(int arr[],int low,int high){
    if(low<high){
        int partition=index(arr,low,high);
        quickSort(arr,low,partition-1);
        quickSort(arr,partition+1,high);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    quickSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
