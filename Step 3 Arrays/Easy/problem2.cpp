//Problem 2:- Finding the second Largest Element in the array

//Brute Force Method:
//First Sort the given array by using quick Sort
//Then run a for loop from the second last element till the first index to know what the second largest element is
//TC:- O(NlogN)+O(N)
//SC:- O(1)
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //After Quick Sort

    int largest=arr[n-1];
    int secondLargest=-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]!=largest){
            secondLargest=arr[i];
            break; 
        }
    }

    cout<<secondLargest;
}

//Better Solution:-
//TC:- O(N)+O(N)
//SC:- O(1)
//Fisrt iterate through the entire array to find the largest guy
//Then again iterate one more time for finding the second largest
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int largest=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }

    int secondLargest=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>secondLargest && arr[i]!=largest){
            secondLargest=arr[i];
        }
    }
    cout<<secondLargest;
}

//Optimised Solution:-
// Here maintain two pointers, one for the largest and the other for second largest..., run a single for loop and try to find the second largest
//TC:- O(N)
//SC:- O(1)
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int largest=arr[0] ;
    int secondLargest=-1;
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            secondLargest=largest;
            largest=arr[i];
        }
        else if(arr[i]!=largest && arr[i]>secondLargest){
            secondLargest=arr[i];
        }
    }

    cout<<secondLargest;
}

//CODE SUBMISSION:-
int secondLargest(vector<int> a, int n){
    int largest=a[0];
    int slargest=-1;
    for(int i=0;i<n;i++){
        if(a[i]>largest){
            slargest=largest;
            largest=a[i];
        }
        else if(a[i]<largest && a[i]>slargest){
            slargest=a[i];
        }
    }
    return slargest;
}
int secondSmallest(vector<int> a,int n){
    int smallest=a[0];
    int ssmallest=INT_MAX;
    for(int i=0;i<n;i++){
        if(a[i]<smallest){
            ssmallest=smallest;
            smallest=a[i];
        }
        else if(a[i]>smallest && a[i]<ssmallest){
            ssmallest=a[i];
        }
    }
    return ssmallest;
}

vector<int> getSecondOrderElements(int n, vector<int> a) {
    int slargest=secondLargest(a,n);
    int ssmallest=secondSmallest(a,n);
    return {slargest,ssmallest};
}
