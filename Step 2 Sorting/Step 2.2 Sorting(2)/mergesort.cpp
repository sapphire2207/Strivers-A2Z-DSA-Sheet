//MERGE SORT:-

//The algorithm states that DIVIDE and MERGE
//Divide the array in equal ratio by using the indexing instead of creating arrays till we a have a single element.
//Then Merge the two divided arrays by sorting it
//TC - O(N*log2N) - Merging takes N steps and Division is happening 2 times everytime so log2N
//SC - O(N) - we are taking a temporary vector to merge the array elements
#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int low,int middle,int high){
    vector<int> temp;
    int left=low;
    int right=middle+1;

    while(left<=middle && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=middle){
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}

void merge_Sort(int arr[],int low,int high){
    if(low>=high) return;
    int middle=(low+high)/2;
    merge_Sort(arr,low,middle);
    merge_Sort(arr,middle+1,high);
    merge(arr,low,middle,high);
}

void algorithm(int arr[],int n){
    merge_Sort(arr,0,n-1);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    algorithm(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}