//BUBBLE SORT:-

//The algorithm is to push the maximum element to the end of the array by adjacent swappings
//TC - O(N^2) for the worst and the average case
// But for the best case it can be optimised i.e O(N) since the code will run only from 0 to n-1
//SC - O(1)
#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[],int n){
    //since we are looping till the (n-i)th index everytime i.e 0->n-1 && 0->n-2 && 0->n-3....
    //let's put the i value from the n-1 index to the second guy i.e till 1 (not till zero because one element is always sorted)
    for(int i=n-1;i>=1;i--){
        int didSwap=0;
        //Now we are going from the first index and till the (n-2)th index because swapping can take place till (n-2)th index only. Suppose if i=n-1, so while checking the maximum guy it compares itself with the next index, so no element is present after that. Therefore we go till the n-2th index.

        //if i=5 then inner loop will go from 0 to 4 but it can check which element is maximum till the 5th index.
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                int temporary=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temporary;
                didSwap++;
            }
        }
        if(didSwap == 0){
            break;
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

    bubble_sort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}