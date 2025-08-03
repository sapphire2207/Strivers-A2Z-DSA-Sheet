//Problem-10:- FINDING MISSING ELEMENT IN THE GIVEN ARRAY
//You will be given an array with elements from 1 to N, but the size is N-1, since one element is missing

//Brute Force Method:-
//Here we are linear searching for each element, whether it is present in the given array
//  For each number between 1 to N, we will try to find it in the given array using linear search. And if we don’t find any of them, we will return the number.

//TC - In the worst case it may go upto O(N*N) --> O(N^2)
//SC - O(1) - No extra space is used while solving the problem
#include<bits/stdc++.h>
using namespace std;

void missingElement(int arr[],int n){
        for(int i=1;i<=n;i++){
        int count=0;
        for(int j=0;j<n-1;j++){
            if(arr[j]==i){
                count++;
                break;
            }
        }
        if(count==0){
            cout<<"The missing number is: "<<i<<endl;
        }
    }
}

int main(){
    int n;
    cin>>n;

    int arr[n-1];
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }

    missingElement(arr,n);

    return 0;
}


//Better Solution:-
//We are using the hashing approach to solve this problem
// Using the hashing technique, we will store the frequency of each element of the given array. Now, the number( i.e. between 1 to N) for which the frequency will be 0, will be returned. 

//TC- O(N+N) - for hashing the given array elements and for finding the unkonwn element in the hash array
//SC- O(N) - using an extra hash array for solcing the problem
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n-1];
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }

    int hash[n+1]={0};
    for(int i=0;i<n-1;i++){
        hash[arr[i]]++;
    }

    for(int i=1;i<n;i++){
        if(hash[i]==0){
            cout<<"Missing Number is: "<<i<<endl;
        }
    }

    return 0;
}

//Optimal Method 1:-
//First calculate the sum using the formula of sum of 'n' natural numbers and then iterate thorugh the entire array and add the elements, then subtract the Real Sum and the Array Sum, then you will get the required missing number
// We know that the summation of the first N numbers is (N*(N+1))/2. We can say this S1. Now, in the given array, every number between 1 to N except one number is present. So, if we add the numbers of the array (say S2), the difference between S1 and S2 will be the missing number. Because, while adding all the numbers of the array, we did not add that particular number that is missing.

//TC- O(N)
//SC- O(1)
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n-1];
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }

    int sum = (n*(n+1)/2);

    int arraySum=0;
    for(int i=0;i<n-1;i++){
        arraySum=+arr[i];
    }

    cout<<"The Missing number is:"<< (sum-arraySum)<<endl;
}

// Optimal Method 2:-
// Using XOR Method, XOR of two same numbers is zero, and the XOR of zero and the number is the number itself
// So XOR the given array elements and the numbers from 1 to N

// Two important properties of XOR are the following:
// XOR of two same numbers is always 0 i.e. a ^ a = 0. ←Property 1.
// XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a.  ←Property 2

// Now, let’s XOR all the numbers between 1 to N.
// xor1 = 1^2^.......^N

// Let’s XOR all the numbers in the given array.
// xor2 = 1^2^......^N (contains all the numbers except the missing one).

// Now, if we perform XOR between xor1 and xor2, we will get:
// xor1 ^ xor2 = (1^1)^(2^2)^........^(missing Number)^.....^(N^N)

// Here all the numbers except the missing number will form a pair and each pair will result in 0 according to the XOR property. The result will be = 0 ^ (missing number) = missing number (according to property 2).So, if we perform the XOR of the numbers 1 to N with the XOR of the array elements, we will be left with the missing number.

//TC:- O(N) --> it is useful for bigger numbers like 10^5 etc
//SC:- O(1)
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n-1];
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }

    int xor1=0;
    int xor2=0;
    for(int i=0;i<n-1;i++){
        xor2=xor2^arr[i];
        xor1=xor1^(i+1);
    }
    xor1=xor1^n;
    cout<<"The Missing number is: "<< (xor1^xor2);

    return 0;
}