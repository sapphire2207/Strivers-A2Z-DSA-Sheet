//SELECTION SORT:-

// The algorithm is select the MINIMUM guy and SWAP it with the fisrt guy, similarly select the next minimum and swap it with the second guy;
//TC - n+n-1+n-2+n-3+......+2+1 = Sum of N natural numbers -> O(N^2)
//SC - O(1)
#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[],int n){
    //We are going till the second last element of the array for SWAPPING, so this loop is for swapping the ith index and the minimum index
    for(int i=0;i<=n-2;i++){
        int minimum=i;
        //we are going till the last element of the array to find where the minimum element is and store that index for swapping it in the further step
        for(int j=i+1;j<=n-1;j++){
            if(arr[j]<arr[minimum]){
                minimum=j;
            }
        }
        //Swapping of the ith index and the minimum guy
        int temporary=arr[minimum];
        arr[minimum]=arr[i];
        arr[i]=temporary;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    selection_sort(arr,n);

    for(int i=0;i<n;i++){
        cout<<i<<" ";
    }
    return 0;
}